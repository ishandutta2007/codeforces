#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 2005;
const int mod = 1e9+7;

int dp[N][N][2];
int d,k;
string a,b;

void minus_(){
    int k = a.size()-1;
    a[k]--;
    while(a[k] < '0'){
        a[k] = '9';
        k--;a[k]--;
    }
}

int f(int i,int m,int flag,string &c){
    int &ret = dp[i][m][flag];
    if(i == b.size())
        return !m;
    if(ret != -1)
        return ret;
    ret = 0;
    if(i&1){
        if(flag && d > c[i]-'0') return 0;
        if(d < (c[i]-'0'))
            ret =  f(i+1,(m*10+d)%k,0,c);
        else
            ret =  f(i+1,(m*10+d)%k,flag,c);
        ret %= mod;
        return ret;
    }
    else{
        for(int j = 0;j<=9;j++){
            if(flag && j > c[i]-'0') break;
            if(j == d || (!i && !j)) continue;
            if(j <  (c[i]-'0') )
                ret += f(i+1,(m*10+j)%k,0,c);
            else
                ret += f(i+1,(m*10+j)%k,flag,c);
            ret %= mod;
        }
        return ret;
    }
}


int main(){
    cin >> k >> d >> a >> b;
    minus_();
    memset(dp,-1,sizeof(dp));
    int upper = f(0,0,1,b);
    memset(dp,-1,sizeof(dp));
    int lower = f(0,0,1,a);
    int sol = upper-lower;
    if(sol < 0) sol += mod;
    cout << sol << endl;
}