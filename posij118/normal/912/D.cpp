#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    long double r;
    long double c=1.0;
    pair<long double, pair<int, int> > x;
    long double ans=0.0;
    cin >> n >> m >> r >> k;

    long double a[n];
    long double b[m];

    for(int i=0; i<n; i++){
        a[i]=min(c, min(r/(n-r+1), min((i+1)/(n-r+1), (n-i)/(n-r+1))));
    }

    for(int i=0; i<m; i++){
        b[i]=min(c, min(r/(m-r+1), min((i+1)/(m-r+1), (m-i)/(m-r+1))));
    }

    priority_queue<pair<long double, pair<int, int> > > active;
    set<pair<int, int> > visited;

    active.push(make_pair(a[n/2]*b[m/2], make_pair(n/2, m/2)));
    visited.insert(make_pair(n/2, m/2));

    for(int i=0; i<k; i++){
        x=active.top();
        active.pop();
        ans+=x.first;

        if(x.second.first>0){
            if(visited.count(make_pair(x.second.first-1, x.second.second))==0){
                visited.insert(make_pair(x.second.first-1, x.second.second));
                active.push(make_pair(a[x.second.first-1]*b[x.second.second], make_pair(x.second.first-1, x.second.second)));
            }
        }

        if(x.second.second>0){
            if(visited.count(make_pair(x.second.first, x.second.second-1))==0){
                visited.insert(make_pair(x.second.first, x.second.second-1));
                active.push(make_pair(a[x.second.first]*b[x.second.second-1], make_pair(x.second.first, x.second.second-1)));
            }
        }

        if(x.second.first<n-1){
            if(visited.count(make_pair(x.second.first+1, x.second.second))==0){
                visited.insert(make_pair(x.second.first+1, x.second.second));
                active.push(make_pair(a[x.second.first+1]*b[x.second.second], make_pair(x.second.first+1, x.second.second)));
            }
        }

        if(x.second.second<m-1){
            if(visited.count(make_pair(x.second.first, x.second.second+1))==0){
                visited.insert(make_pair(x.second.first, x.second.second+1));
                active.push(make_pair(a[x.second.first]*b[x.second.second+1], make_pair(x.second.first, x.second.second+1)));
            }
        }
    }


    cout << setprecision(15) << ans;



}