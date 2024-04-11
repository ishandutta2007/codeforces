//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000001;
const ll mod=1000000007;
const int N=1000010;
int x[N],y[N];
int cnt[2][2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        x[i]/=2;
        y[i]/=2;
        cnt[x[i]%2][y[i]%2]++;
    }
    ll res=0ll;
    for (int x1=0;x1<2;x1++){
        for (int y1=0;y1<2;y1++){
            ll m1=cnt[x1][y1]--;
            for (int x2=0;x2<2;x2++){
                for (int y2=0;y2<2;y2++){
                    ll m2=m1*(cnt[x2][y2]--);
                    for (int x3=0;x3<2;x3++){
                        for (int y3=0;y3<2;y3++){
                            ll m3=(m2*cnt[x3][y3]);
//                            ll S=abs((x2-x1)*(y1+y2)+(x3-x2)*(y2+y3)+(x1-x3)*(y3+y1));
                            ll D=__gcd(abs(x2-x1),abs(y2-y1))+__gcd(abs(x3-x2),abs(y3-y2))+__gcd(abs(x1-x3),abs(y1-y3))-1+4;
                            if (D%2) {
//                                if (m3) cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<" "<<m3<<" "<<S<<" "<<D<<endl;
//                                break;
                                res+=m3;
                            }
                        }
                    }



                    cnt[x2][y2]++;
                }
            }
            cnt[x1][y1]++;
        }
    }
    cout<<res/6ll<<endl;

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}