#include <bits/stdc++.h>
#define pb push_back
#define maxn 100100
using namespace std;

char str[maxn];

int main(){
    scanf(" %s",str);
    int n = strlen(str);
    for(int i=1;i<n-1;i++){
        vector<char> v;
        v.pb(str[i-1]);
        v.pb(str[i]);
        v.pb(str[i+1]);
        sort(v.begin(),v.end());
        if(v[0] == 'A' && v[1] == 'B' && v[2] == 'C'){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}