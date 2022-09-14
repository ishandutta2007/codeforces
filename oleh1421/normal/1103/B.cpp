#include <bits/stdc++.h>
typedef long long ll;
//#define endl '\n'
///#define int long long
using namespace std;

int32_t main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int cnt0=0;
    int cnt1=0;
    string tt;
    while (cin>>tt){
        if (tt=="end" || tt=="mistake") return 0;
        int ind=0;

        for (int i=1;i<=29;i++){
            cout<<"? "<<(1<<(i-1))<<" "<<(1<<i)<<endl;
            char c;cin>>c;
            if (c=='x') break;
            ind=i;
        }
        if (ind==0){
            cout<<"? "<<"2 1"<<endl;
            char c;cin>>c;
            if (c=='x') cout<<"! 1"<<endl;
            else cout<<"! 2"<<endl;
        } else {
            int cur=(1<<ind);
            for (int i=ind-1;i>=0;i--){
                cout<<"? "<<cur<<" "<<cur+(1<<i)<<endl;
                char c;cin>>c;
                if (c=='y') cur^=(1<<i);
            }
            cout<<"! "<<cur+1<<endl;
        }
    }
    return 0;
}