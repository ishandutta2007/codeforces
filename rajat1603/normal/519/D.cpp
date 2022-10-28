#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define N 100001
#define LN 17
#define getchar_unlocked getchar//for codeforces and timus
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
map<long long,long long> dp[27];
string x;
long long c[200001];
int main(){
    long long score[27];
    long long answer=0;
    for(int i=0;i<26;i++){
        cin>>score[i];
    }
    cin>>x;
    int n=x.size();
    c[0]=score[x[0]-'a'];
    for(int i=1;i<n;i++){
        c[i]=c[i-1]+score[x[i]-'a'];
    }
    dp[x[0]-'a'][0]=1;
    for(int i=1;i<n;i++){
        if(dp[x[i]-'a'].find(c[i]-(score[x[i]-'a']<<1))!=dp[x[i]-'a'].end()){
            answer+=dp[x[i]-'a'][c[i]-(score[x[i]-'a']<<1)];
        }
        dp[x[i]-'a'][c[i-1]]++;
    }
    cout<<answer;
}