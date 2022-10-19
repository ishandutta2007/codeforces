#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,f[N][2],ans;
string s[2];

void cmin(int &x,int y){x=min(x,y);}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>s[0]>>s[1];
    s[0]=s[0]+'0'; s[1]=s[1]+'0';
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for (int i=0;i<n;++i){
        ans+=s[0][i]-'0'+s[1][i]-'0';
        for (int j:{0,1}){
            if (s[j^1][i]=='1'&&s[j][i+1]=='1'){
                cmin(f[i+1][j],f[i][j]+1);
                cmin(f[i+2][j^1],f[i][j]+1);
            }
            else{
                if (s[j^1][i]=='1'){
                    cmin(f[i+1][j^1],f[i][j]);
                    cmin(f[i+1][j],f[i][j]+1);
                }
                else{
                    cmin(f[i+1][j],f[i][j]);
                }
            }
        }
    }
    cout<<(ans-min(f[n][0],f[n][1]))<<'\n';
}