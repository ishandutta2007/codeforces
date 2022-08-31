# include <cstdio>
# include <algorithm>

using namespace std;

int ar[1000000];
int nonneg[1000000],nonpos[1000000];

int main()
{
    FILE *f1,*f2;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");
    
    int N;
    fscanf(f1,"%d",&N);
    
    for(int i=0;i<N;i++)
        fscanf(f1,"%d",ar+i);
    
    nonneg[0]=(ar[0]>=0)?1:0;
    for(int i=1;i<N;i++)
        nonneg[i]=nonneg[i-1]+((ar[i]>=0)?1:0);
    
    nonpos[N-1]=(ar[N-1]<=0)?1:0;
    for(int i=N-2;i>=0;i--)
        nonpos[i]=nonpos[i+1]+((ar[i]<=0)?1:0);
    
    int best=N;
    for(int i=0;i<N-1;i++)
        best=min(best,nonneg[i]+nonpos[i+1]);
    
    fprintf(f2,"%d\n",best);
    
    fclose(f1);
    fclose(f2);
    return 0;
}