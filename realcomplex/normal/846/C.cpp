#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

ll k[5005];

void ini(){
    for(int j = 1;j<5005;j++)k[j]+=k[j-1];
}

ll range(int a,int b){
    if(a == 0) return k[b-1];
    else return k[b-1]-k[a-1];
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int j = 0;j<n;j++)cin >> k[j];
    ini();
    ll res = -INF;
    int p0,p1,p2;
    p0 = 0;
    p1 = 0;
    p2 = 0;
    ll cur = 0;
    int t,t1,t2;
    ll dm;
    for(int j = 0;j<=n;j++){
        t = j;
        dm = -INF;
        cur = 0;
        for(int i = j;i>=0;i--){
            if(range(0,i)-range(i,j) > dm){
                dm = range(0,i)-range(i,j);
                t1 = i;
            }

        }
        cur += dm;
        dm = -INF;
        for(int i = j;i<=n;i++){
            if(range(j,i)-range(i,n) > dm){
                dm = range(j,i)-range(i,n);
                t2 = i;
            }
        }
        cur += dm;
        if(cur > res){
            res = cur;
            p0 = t1;
            p1 = t;
            p2 = t2;
        }
    }
    cout << p0 << " " << p1 << " " << p2;
    return 0;
}