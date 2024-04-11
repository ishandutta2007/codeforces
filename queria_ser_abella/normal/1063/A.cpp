#include <bits/stdc++.h>
#define pii pair<int,char>
#define maxn 300300
#define debug printf
typedef long long ll;
using namespace std;

char str[maxn];

int main(){
    int n;
    scanf("%d %s",&n,&str);
    sort(str,str+n);
    printf("%s\n",str);
}