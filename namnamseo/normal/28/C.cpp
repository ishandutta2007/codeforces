#include <cstdio>
void read(int& a){ scanf("%d",&a); }
void read(double& a){ scanf("%lf",&a); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }
int n,m;
int sz[51];
double dpval[51][51];
double dpcnt[51][51];

double combi[51][51];

void bc(){
    int i,j;
    combi[0][0]=1;
    for(i=1;i<=50;++i){
        for(j=1;j<i;++j)combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
        combi[i][0]=combi[i][i]=1;
    }
}

int main()
{
    bc();
    
    read(n,m);
    int i,j,k,t,l;
    for(i=1;i<=m;++i) read(sz[i]);
    dpcnt[0][0]=1;
    double val=0, cnt=0;
    for(i=1; i<=n; ++i){
        for(j=1; j<=m; ++j){
            // max queue of j is i.
            // max queue of 1~(j-1) < i.
            //printf("Trial; max queue of %d is %d\n",j,i);
            dpcnt[0][0]=1;
            for(k=1; k<=m; ++k){
                int minstu, maxstu;
                
                if(k<j) minstu=0, maxstu = (i-1) * sz[k];
                else if(k==j) minstu=(i-1)*sz[k]+1, maxstu=i*sz[k];
                else minstu=0, maxstu=i*sz[k];
                //printf("Visit %d; student %d ~ %d\n",k, minstu, maxstu);
                
                for(t=0; t<=n; ++t) dpcnt[k][t]=0, dpval[k][t]=0;
                
                for(t=minstu; t<=maxstu; ++t){
                    for(l=t;l<=n;++l){
                        dpcnt[k][l] += combi[n-(l-t)][t] * dpcnt[k-1][l-t];
                    }
                }
            }
            //printf("cnt %.0f\n",dpcnt[m][n]);
            val += i*dpcnt[m][n];
            cnt += dpcnt[m][n];
        }
    }
    //printf("allcnt %.5f\n",cnt);
    printf("%.15f\n",val/cnt);
    return 0;
}