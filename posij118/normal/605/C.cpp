#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long > > conv;

long long mul(pair<long long, long long> x, pair<long long, long long> y,
    pair<long long, long long> z){

        long long ux, uy, vx, vy;
        ux = y.first - x.first;
        uy = y.second - x.second;
        vx = z.first - y.first;
        vy = z.second - y.second;

        return ux * vy - uy * vx;
    }

double mult(pair<long long, long long> x, pair<double, double> y,
    pair<long long, long long> z){

        double ux, uy, vx, vy;
        ux = y.first - x.first;
        uy = y.second - x.second;
        vx = z.first - y.first;
        vy = z.second - y.second;

        return ux * vy - uy * vx;
    }


bool inside(pair<double, double> x){
    for(int i = 1; i<conv.size(); i++){
        if(mult(conv[i - 1], x, conv[i]) * mult(conv[conv.size() - 1], x, conv[0]) < 0) return 0;
    }

    return 1;
}

void create(vector<pair<long long, long long> > v){
    sort(v.begin(), v.end());
    for(int i = 0; i<v.size(); i++){
        if(conv.size() <= 1){
            conv.push_back(v[i]);
            continue;
        }

        while(conv.size() > 1){
            if(mul(conv[conv.size() - 2], conv[conv.size() - 1], v[i]) >= 0) conv.pop_back();
            else break;
        }

        conv.push_back(v[i]);
    }
}


int main(){
    double d, h, mid;
    long long n, p, q;
    cin >> n >> p >> q;

    d = 0.0;
    h = 1e9 + 0.0;
    long long maf, mas;
    maf = 0;
    mas = 0;

    vector<pair<long long, long long> > a(n + 2);
    for(int i = 0; i<n; i++){
        cin >> a[i].first >> a[i].second;
        maf = max(maf, a[i].first);
        mas = max(mas, a[i].second);
    }

    a[n] = make_pair(0LL, mas);
    a[n + 1] = make_pair(0LL, 0LL);

    create(a);
    conv.push_back(make_pair(maf, 0LL));
    for(int i = 0; i<70; i++){
        mid = (d + h) / 2;
        if(inside(make_pair(mid, (mid * q) / p))) d = mid;
        else h = mid;
    }

    cout << setprecision(10) << p/mid << endl;



}