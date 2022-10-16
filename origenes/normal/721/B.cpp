#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    int n, k, cnt[105];
    cin>>n>>k;
    string s;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++){
        cin>>s;
        cnt[s.length()]++;
    }
    cin>>s;
    int len=s.length(), mint=0, maxt;
    for(int i=0; i<len; i++){
        mint+=cnt[i];
    }
    maxt=mint+cnt[len];
    mint++;
    mint+=(mint-1)/k*5;
    maxt+=(maxt-1)/k*5;
    cout<<mint<<' '<<maxt<<endl;
    return 0;
}