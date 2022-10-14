#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll M,S;
string s,ans2,ans1;
int main (){
    cin >> M >> S;
    // cout << S << M*9 ;
    if (M==1 and S==0){
        cout << "0 0\n";
        return 0;
    }
    if (0<M and 0<S and S<=(M*9)){
        int Stemp=S, Mtemp=M;
        for (int i=1; i<=M; i++){
            if (S>9){
                S-=9;
                ans2.push_back('9');
            } else{
                ans2.push_back(S+'0');
                S=0;
            }
        }
        S=Stemp;
        ans1=ans2;
        reverse(ans1.begin(),ans1.end());
        if (ans1[0]=='0'){
            for (int i=1; i<M; i++){
                if (ans1[i]!='0'){
                    ans1[i]--;
                    break;
                }
            }
            ans1[0]='1';
        }
        cout << ans1 << " " << ans2 << endl;
    } else{
        cout << "-1 -1\n";
    }
}