#include <cstdio>
#include <map>
using namespace std;
 
typedef pair<int,int> P;
map<int,P> arr;
int val[6]={4,8,15,16,23,42};
int ret[7];
 
P getquery(int i,int j) {
    printf("? %d %d\n",i,j);
    fflush(stdout);
    fflush(stdin);
    int x;
    scanf("%d",&x);
    return arr[x];
}
 
void solve(int a,int b,int c) {
    P ab=getquery(a,b);
    P bc=getquery(b,c);
    if (ab.first==bc.first) {
        ret[b]=ab.first;
        ret[a]=ab.second;
        ret[c]=bc.second;
    }
    if (ab.first==bc.second) {
        ret[a]=ab.second;
        ret[b]=ab.first;
        ret[c]=bc.first;
    }
    if (ab.second==bc.first) {
        ret[a]=ab.first;
        ret[b]=ab.second;
        ret[c]=bc.second;
    }
    if (ab.second==bc.second) {
        ret[a]=ab.first;
        ret[b]=ab.second;
        ret[c]=bc.first;
    }
}
 
int main(void) {
    for(int i=0;i<6;i++) {
        for(int j=i+1;j<6;j++) {
            arr[val[i]*val[j]]=P(val[i],val[j]);
        }
    }
    solve(1,2,3);
    solve(4,5,6);
    printf("!");
    for(int i=1;i<=6;i++) {
        printf(" %d",ret[i]);
    }
    printf("\n");
    return 0;
}