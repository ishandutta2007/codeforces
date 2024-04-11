#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;

int used[110000];
int posl[110];
int posr[110];
int before[110000];
int after[110000];
int L,b,f,n;


void clear(int num){
    for (int i=posl[num];i<posr[num];i++)
    used[i]--;
}

int find(int len){
    before[0]=(b+10)*(used[0]==0);
    for (int i=1;i<L;i++)
    before[i]=(before[i-1]+1)*(used[i]==0);
    after[L-1]=(f+10)*(used[L-1]==0);
    for (int i=L-2;i>=0;i--)
    after[i]=(after[i+1]+1)*(used[i]==0);
    for (int i=0;i<L-len+1;i++)
    if ((i==0 || before[i-1]>=b)  && after[i]>=len+f)
        return i;
    return -1;
}


int main(){
    scanf("%d %d %d",&L,&b,&f);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
    int type,len;
    scanf("%d %d",&type,&len);
    if (type==2){
        --len;
        clear(len);
        continue;
    }
    int tmp=find(len);
    if (tmp==-1){
        printf("-1\n");
        continue;
    }
    for (int j=tmp-b;j<tmp+f;j++)
        assert(j<0 || j>=L || used[j]==0);
    for (int j=tmp;j<tmp+len;j++)
        used[j]++;
    posl[i]=tmp;
    posr[i]=tmp+len;
    printf("%d\n",posl[i]);
    }
    return 0;  
}