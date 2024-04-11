#pragma comment(linker, "/STACK:36777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

void conv(int c){
    string s;
    while(c){
        c--;
        s.pb('A'+c%26);
        c/=26;
    }
    reverse(s.begin(),s.end());
    printf("%s",s.c_str());
}
int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif
    char s[111];
    int n;
    cin>>n;gets(s);
    REP(i,n){
        gets(s);
        bool f=false;
        int m = strlen(s);
        FOR(j,1,m-1) if(isalpha(s[j]) && isdigit(s[j-1]) && isdigit(s[j+1]))
            f=true;

        if(f){
            int r=0,c=0;
            f=false;
            FOR(j,1,m){
                if(isdigit(s[j])){
                    if(f) c=10*c+s[j]-'0';
                    else r=10*r+s[j]-'0';
                }else f=true;
            }
            conv(c);
            printf("%d",r);
            puts("");
        }else{
            int r=0,c=0;
            REP(j,m) if(isdigit(s[j]))
                r=10*r+s[j]-'0';
            REP(j,m) if(isdigit(s[j]))
                s[j]=0;
            m=strlen(s);
            int q=1;
            for(int j= m-1;j>=0;j--){
                c+=(s[j]-'A'+1)*q;
                q*=26;
            }

            printf("R%dC%d\n",r,c);
        }
    }
    return 0;
}