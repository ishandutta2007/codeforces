#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;


int h, m, n;
bool table[50000];

map<int, int>mp;

int main(){
    scanf("%d%d%d", &h, &m, &n);
    char sign[16];
    int id, hash;
    int ans=0;

    for(int i=0; i<n; i++){
        scanf("%s%d", sign, &id);
        if(sign[0]=='+'){
            scanf("%d", &hash);

            for(;table[hash];){
                ans++;
                hash=(hash+m)%h;
            }
            table[hash]=1;
            mp[id]=hash;
        }else{
            table[mp[id]]=0;
        }
    }
    printf("%d\n", ans);
    return 0;
}