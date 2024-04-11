#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define AIN(a, b, c) assert(b <= a && a <= c)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid,s,e
#define clrgt rgt,mid+1,ed,s,e
#define inf (1<<29)
#define ii64 long long
#define MX 130

typedef pair<int,int> pii;

struct matrix {
    double mat[MX][MX];
    matrix(){
        CLR(mat);
    }
}a,res;

int n, x, lmt;
double pr[MX];

void buildMatrix(){
    int i, j;
    CLR(a.mat);
    for(i = 1; i < lmt; i++)a.mat[lmt][i] = 1;

    for(i = 0; i < lmt; i++){
        for(j = 0; j < lmt; j++){
            int k = i ^ j;
            a.mat[i][j] = pr[k];
        }
    }
}

void printMat(matrix a){
    int i,j;
    for(i=0;i<=lmt;i++){
        for(j=0;j<=lmt;j++){
            printf("%8.2lf",a.mat[i][j]);
        }
        puts("");
    }
    puts("");
}

matrix mult(matrix a, matrix b){
    int i,j, k;
    matrix ret;
    for(i = 0; i <= lmt; i++){
        for(j = 0; j <= lmt; j++){
            ret.mat[i][j] = 0;
            for(k = 0; k <= lmt; k++){
                ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return ret;
}

int main(){
    int i,j,b;
    scanf("%d %d", &n, &x);
    for(i = 0; i <= x; i++)scanf("%lf", &pr[i]);
    lmt = log2(x) + 1;
    lmt = 1 << lmt;
    for(i = x+1; i <= lmt; i++) pr[i] = 0;
    buildMatrix();
    //printMat(a);
    b = n + 1;
    CLR(res.mat);
    for(i = 0; i <= lmt; i++)res.mat[i][i] = 1;
    while(b){
        if(b&1) res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    //printMat(res);
    printf("%.8lf\n",res.mat[lmt][0]);

	return 0;
}