#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int K = 5;

vector < int > v;
int n,k,y,sol = 0,cnt[100];

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++){
        y = 0;
        for(int j = 0;j<k;j++){
            char x = '\0';
            while(x != '0' && x != '1') 
                x = getchar();
            y += (1 << j) * int(x - '0');
        }
        cnt[y]++;
    }
    for(int i = 0;i<100;i++)
        if(cnt[i])
            v.push_back(i);
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v.size();j++){
            if(!(v[i] & v[j])) sol = 1;
        }
    }
    if(sol){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}