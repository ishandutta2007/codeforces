//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
using namespace std;
const int N=600010;
const ll mod=1000000007;
map<string,int>mp;
int dx[8],dy[8];
string s;
void solve(){
    cout<<1<<" "<<1<<endl;
    int x=1,y=1;
    int r=1;
    for (int i=1;i<=7;i++){
        cin>>s;
        if (s=="Done") return;
        int dX=dx[mp[s]];
        int dY=dy[mp[s]];
        if (dX) r^=1;
        if (i%2==r){
            x++;
            cout<<x<<" "<<y<<endl;
            continue;
        }
        if (y==1){
            for (int i=2;i<=7;i++){
                y=i;
                cout<<x<<" "<<y<<endl;
                cin>>s;
                if (s=="Done") return;
                if (dx[mp[s]]) {
                    r^=1;
                    break;
                }
            }
            x++;
            cout<<x<<" "<<y<<endl;
            cin>>s;
            if (s=="Done") return;
            if (dx[mp[s]]) {
                r^=1;
            }
            y=8;
            cout<<x<<" "<<y<<endl;
        } else {
            for (int i=7;i>=2;i--){
                y=i;
                cout<<x<<" "<<y<<endl;
                cin>>s;
                if (s=="Done") return;
                if (dx[mp[s]]) {
                    r^=1;
                    break;
                }
            }
            x++;
            cout<<x<<" "<<y<<endl;
            cin>>s;
            if (s=="Done") return;
            if (dx[mp[s]]) {
                r^=1;
            }
            y=1;
            cout<<x<<" "<<y<<endl;
        }

    }
    cin>>s;
    if (s=="Done") return;
    if (dx[mp[s]]) {
        r^=1;
    }
    x=1;
    y=1;
    cout<<x<<" "<<y<<endl;
    r^=1;
    ///almost copy-pasted part
    for (int i=1;i<=7;i++){
        cin>>s;
        if (s=="Done") return;
        int dX=dx[mp[s]];
        int dY=dy[mp[s]];
        if (dX) r^=1;
        if (i%2==r){
            x++;
            cout<<x<<" "<<y<<endl;
            continue;
        }
        if (y==1){
            for (int i=2;i<=7;i++){
                y=i;
                cout<<x<<" "<<y<<endl;
                cin>>s;
                if (s=="Done") return;
                if (dx[mp[s]]) {
                    r^=1;
                    break;
                }
            }
            x++;
            cout<<x<<" "<<y<<endl;
            cin>>s;
            if (s=="Done") return;
            if (dx[mp[s]]) {
                r^=1;
            }
            y=8;
            cout<<x<<" "<<y<<endl;
        } else {
            for (int i=7;i>=2;i--){
                y=i;
                cout<<x<<" "<<y<<endl;
                cin>>s;
                if (s=="Done") return;
                if (dx[mp[s]]) {
                    r^=1;
                    break;
                }
            }
            x++;
            cout<<x<<" "<<y<<endl;
            cin>>s;
            if (s=="Done") return;
            if (dx[mp[s]]) {
                r^=1;
            }
            y=1;
            cout<<x<<" "<<y<<endl;
        }

    }

    ///almost copy-pasted part
    exit(1);
}

int32_t main()
{
    mp["Right"]=0;
    dy[0]=1;
    mp["Left"]=1;
    dy[0]=-1;
    mp["Up"]=2;
    dx[2]=-1;
    mp["Down"]=3;
    dx[3]=1;
    mp["Down-Right"]=4;
    dy[4]=1;
    dx[4]=1;
    mp["Down-Left"]=5;
    dy[5]=-1;
    dx[5]=1;
    mp["Up-Left"]=6;
    dy[6]=-1;
    dx[6]=-1;
    mp["Up-Right"]=7;
    dy[7]=1;
    dx[7]=-1;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}