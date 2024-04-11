#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int MAXN = 500000 + 5;
char str1[MAXN],str2[MAXN],str[MAXN];
int N;
int cnt;
int len1;

bool is(char ch){
    return ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '<' || ch == '>');
}

int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin >> N;
    scanf("%d",&N);
    str1[len1++] = '<';
    str1[len1++] = '3';
    FOR(i,1,N){
        scanf("%s",str);
        //DEBUG(s);
        //str1 = str1 + s + "<3";
        strcpy(str1+len1,str);
        len1 += strlen(str);
        str1[len1++] = '<';
        str1[len1++] = '3';
    }
    scanf("%s",str2);
    int len2 = strlen(str2);
    //DEBUG(str1);
    int j = 0,cnt = 0;
    bool flag = true;
    FOR(i,0,len2-1){
        if(str1[j] == str2[i]){
            cnt++;
            j++;
        }
        else{
            if(is(str2[i])){
                //j++;
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
    }
    if(cnt == len1){
        puts("yes");
    }
    else puts("no");
    return 0;
}