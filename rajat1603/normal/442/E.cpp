#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const double eps = 1e-10;
int w , h , n;
pair < int , int > arr[N];
double ans;
double dist[N][N];
const double pi = acos(-1.0);
double fix(double x){
    while(x < 0){
        x += 2 * pi;
    }
    while(x > 2 * pi){
        x -= 2 * pi;
    }
    return x;
}
bool check(int idx , double r){
    r += eps / 10;
    vector < pair < double , int > > v;
    v.clear();
    int sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(i != idx){
            if(dist[idx][i] <= 2 * r && dist[idx][i] >= 0.6){
                double theta = fix(atan2(arr[i].second - arr[idx].second , arr[i].first - arr[idx].first));
                double phi = acos(dist[idx][i] / (2.0 * r));
                if(phi < 0){
                    phi = -1;
                }
                double l = fix(theta - phi);
                double r = fix(theta + phi);
                if(l <= r){
                    v.push_back({l , 1});
                    v.push_back({r , -1});
                }
                else{
                    v.push_back({l , 1});
                    ++sum;
                    v.push_back({r , -1});
                }
            }
        }
    }
    if(arr[idx].first <= r){
        double theta = atan2(0 , -1);
        double phi = acos(1.0 * arr[idx].first / r);
        if(phi < 0){
            phi = -1;
        }
        double l = fix(theta - phi);
        double r = fix(theta + phi);
        if(l <= r){
            v.push_back({l , 2});
            v.push_back({r , -2});
        }
        else{
            v.push_back({l , 2});
            sum += 2;
            v.push_back({r , -2});
        }
    }
    if(arr[idx].first + r >= w){
        double theta = atan2(0 , 1);
        double phi = acos(1.0 * (w - arr[idx].first) / r);
        if(phi < 0){
            phi = -1;
        }
        double l = fix(theta - phi);
        double r = fix(theta + phi);
        if(l <= r){
            v.push_back({l , 2});
            v.push_back({r , -2});
        }
        else{
            v.push_back({l , 2});
            sum += 2;
            v.push_back({r , -2});
        }
    }
    if(arr[idx].second <= r){
        double theta = atan2(-1 , 0);
        double phi = acos(1.0 * arr[idx].second / r);
        if(phi < 0){
            phi = -1;
        }
        double l = fix(theta - phi);
        double r = fix(theta + phi);
        if(l <= r){
            v.push_back({l , 2});
            v.push_back({r , -2});
        }
        else{
            v.push_back({l , 2});
            sum += 2;
            v.push_back({r , -2});
        }
    }
    if(arr[idx].second + r >= h){
        double theta = atan2(1 , 0);
        double phi = acos(1.0 * (h - arr[idx].second) / r);
        if(phi < 0){
            phi = -1;
        }
        double l = fix(theta - phi);
        double r = fix(theta + phi);
        if(l <= r){
            v.push_back({l , 2});
            v.push_back({r , -2});
        }
        else{
            v.push_back({l , 2});
            sum += 2;
            v.push_back({r , -2});
        }
    }
    if(sum <= 1){
        return 1;
    }
    sort(v.begin() , v.end());
    for(auto it : v){
        sum += it.second;
        if(sum <= 1){
            return 1;
        }
    }
    return 0;
}
void solve(int idx){
    if(!check(idx , ans + eps)){
        return;
    }
    double l = ans + eps;
    double r = 2e6;
    for(int i = 0 ; i < 50 ; ++i){
        double mid = (l + r) / 2;
        if(check(idx , mid)){
            l = mid;
        }
        else{
            r = mid - eps;
        }
    }
    ans = max(ans , (l + r) / 2);
}
int main(){
    scanf("%d %d %d" , &w , &h , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    random_shuffle(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        dist[i][i] = 0;
        for(int j = 1 ; j < i ; ++j){
            int dx = arr[i].first - arr[j].first;
            int dy = arr[i].second - arr[j].second;
            dist[i][j] = dist[j][i] = sqrt(1LL * dx * dx + 1LL * dy * dy);
        }
    }
    ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        solve(i);
    }
    printf("%.15lf\n" , ans);
}