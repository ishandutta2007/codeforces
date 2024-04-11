#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>

typedef long long int llint;

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int off = 1<<18;
const int MOD = 1e9 + 7;

int n,mx,cnt = 0;

set <int> s;

int main(){
    scanf("%d %d",&n,&mx);
    for(int i = 0;i<n;i++){
        scanf("%d",&cnt);
        s.insert(cnt);
    }cnt = 0;
    while(!s.empty()){
        while(!s.empty() && (*s.begin())/2 + (*s.begin())%2 <= mx){
            mx = max(*s.begin(),mx);
            s.erase(s.begin());
        }
        if(!s.empty()){
            cnt++;
            mx *= 2;
        }
        else{
            break;
        }
    }
    printf("%d\n",cnt);
}