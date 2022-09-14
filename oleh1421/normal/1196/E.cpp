#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int s0[200001];
int s1[200001];
int s2[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        int b,w;cin>>b>>w;
        if (3*b+1<w || b>3*w+1){
            cout<<"NO\n";
           // return 1;
        } else {
            cout<<"YES\n";
            for (int i=2;i<=min(b,w)*2+1;i++){
                cout<<2<<" "<<i<<endl;
            }
            if (w>b){
                w-=b;
                cout<<2<<" "<<b+b+2<<endl;
                w--;
                for (int i=3;i<=b+b+1;i+=2){
                    if (w){
                        cout<<1<<" "<<i<<endl;
                        w--;
                    }
                    if (w){
                        cout<<3<<" "<<i<<endl;
                        w--;
                    }
                }
            } else if (w<b){
               b-=w;
               cout<<2<<" "<<1<<endl;
               b--;
               for (int i=2;i<=w+w+1;i+=2){
                   if (b){
                      cout<<1<<" "<<i<<endl;
                      b--;
                   }
                   if (b){
                      cout<<3<<" "<<i<<endl;
                      b--;
                   }
               }
            }
        }
    }
    return 0;
}