#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

int lst[2 * N];
string s;
int sol = 0;
int n;

int main(){
    memset(lst,-1,sizeof(lst));
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    cin.tie(0);
    int cur = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '0') cur--;
        else cur++;
        if(!cur) sol = max(sol,i+1);
        if(lst[cur + N] != -1){
            sol = max(sol, i - lst[cur + N]);
        }
        else{
            lst[cur + N] = i;
        }
    }
    printf("%d\n",sol);
}