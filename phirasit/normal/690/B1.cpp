#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int NSIZ=1010;
const int mxint=2e9;
typedef pair<int,int> pii;
int n, m, o, re=0;
char a[NSIZ][NSIZ], b[NSIZ];
int chk[NSIZ];
vector<pii> ve;
bool check(int i, int j, int d){
    if(i<0 || i>=n || j<0 || j>=n)return true;
    if(a[i][j]==d+'0'){a[i][j]='0';return true;}
    else return false;
}
void print(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c", a[i][j]);
        }printf("\n");
    }printf("\n");
}
int main(){
    int i, j, k, l;
    scanf("%d", &n);
    pii mn=pii(mxint,mxint), mx=pii(-mxint,-mxint);
    for(i=0; i<n; i++){
        scanf("%s", a[i]);
        for(j=0; j<n; j++){
            if(a[i][j]=='4'){
                mn.F=min(mn.F,i);
                mn.S=min(mn.S,j);
                mx.F=max(mx.F,i);
                mx.S=max(mx.S,j);
            }

        }
    }
    //-----4----
    for(i=mn.F; i<=mx.F; i++){
        for(j=mn.S; j<=mx.S; j++){
            if(!check(i,j,4))goto fail;
        }
    }
    //----2----
    for(i=mn.F; i<=mx.F; i++){
        if(!check(i,mn.S-1,2))goto fail;
        if(!check(i,mx.S+1,2))goto fail;
    }
    for(i=mn.S; i<=mx.S; i++){
        if(!check(mn.F-1,i,2))goto fail;
        if(!check(mx.F+1,i,2))goto fail;
    }
    //----1----
    if(!check(mn.F-1,mn.S-1,1))goto fail;
    if(!check(mn.F-1,mx.S+1,1))goto fail;
    if(!check(mx.F+1,mn.S-1,1))goto fail;
    if(!check(mx.F+1,mx.S+1,1))goto fail;

//    print();
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(a[i][j]!='0')goto fail;
        }
    }
    printf("Yes");
    return 0;
    fail:;
    printf("No");
    return 0;
}