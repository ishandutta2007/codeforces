#include <cstdio>
#include <iostream>

using namespace std;


typedef long long int llint;
typedef short int sint;

const int N = 1005;
const int M = 3e5+500;
const int ALPHA = 28;

llint pref2[N][N][ALPHA];
llint pref[N][N][ALPHA];
llint pic[N][N];
int a[M],b[M],c[M],d[M],e[M];
int n,m,q;

char ch;

llint getprfpref2(int i1,int j1,int i2, int j2,int k){
    return pref2[i2][j2][k] - (i1?pref2[i1-1][j2][k]:0)  - (j1?pref2[i2][j1-1][k]:0) + ((i1&&j1)?pref2[i1-1][j1-1][k]:0);
}

llint getpic(int i1,int j1,int i2, int j2){
    return pic[i2][j2] - (i1?pic[i1-1][j2]:0)  - (j1?pic[i2][j1-1]:0) + ((i1&&j1)?pic[i1-1][j1-1]:0);
}

void precomputesweep(){
    for(int k = 0;k<26;k++){
        for(int i = 0;i<n;i++){
            llint cnt = 0;
            for(int j = 0;j<m;j++){
                cnt += pref[i][j][k];
                pref[i][j][k] = cnt;
            }
        }

        for(int j = 0;j<m;j++){
            llint cnt = 0;
            for(int i = 0;i<n;i++){
                cnt += pref[i][j][k];
                pref[i][j][k] = cnt;
            }
        }
    }
}

void precomputepref(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m ;j++){
            for(int k = 0;k<26;k++){
                pref2[i][j][k] = pref[i][j][k];
                pref[i][j][k] = pref[i][j][k] * k;

                if(k){
                    pref[i][j][k] += pref[i][j][k-1];
                    pref2[i][j][k] += pref2[i][j][k-1];
                }
            }

        }
    }
}


void precomputepref2(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            llint last = 0,cur = 0,mx = pref2[i][j][25];
            for(int k = 0;k<26;k++){
                cur = pref2[i][j][k];
                pref2[i][j][k] = 0;
                if(k)
                    pref2[i][j][k] += k * last -  pref[i][j][k-1];

                pref2[i][j][k] += pref[i][j][25] - pref[i][j][k] - k * (mx - cur);

                if(k > pic[i][j]){
                    pref2[i][j][k] += (q -  mx) * (k - pic[i][j]);

                }
                else{
                    pref2[i][j][k] += (q -  mx) * (pic[i][j] - k);
                }
                last = cur;
            }
        }

    }
}

void precomputeprfpref2(){
    for(int k = 0;k<26;k++){
        for(int i = 0;i<n;i++){
            llint cnt = 0;
            for(int j = 0;j<m;j++){
                cnt += pref2[i][j][k];
                pref2[i][j][k] = cnt;
                if(i) pref2[i][j][k] += pref2[i-1][j][k];

            }
        }
    }
}

void precomputepic(){
    for(int i = 0;i<n;i++){
        llint cnt = 0;
        for(int j = 0;j<m;j++){
            cnt += pref2[i][j][pic[i][j]];
            pic[i][j] = cnt;
            if(i)
                pic[i][j] += pic[i-1][j];
        }


    }
}

int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> ch;
            pic[i][j] = ch - 'a' ;
        }
    }
    for(int i = 0;i<q;i++){
        scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
        a[i]--;b[i]--;c[i]--;d[i]--;
        cin >> ch;
        e[i] = ch - 'a' ;
        pref[a[i]][b[i]][e[i]]++;
        pref[c[i]+1][d[i]+1][e[i]]++;
        pref[a[i]][d[i]+1][e[i]]--;
        pref[c[i]+1][b[i]][e[i]]--;
    }
    precomputesweep();
    precomputepref();

    precomputepref2();
    precomputepic();
    precomputeprfpref2();

    llint sol = 1e17;
    for(int i = 0;i<q;i++){
        sol = min(sol ,getprfpref2(a[i],b[i],c[i],d[i],e[i]) + getpic(0,0,n-1,m-1) - getpic(a[i],b[i],c[i],d[i]));
    }
    printf("%I64d\n",sol);
}