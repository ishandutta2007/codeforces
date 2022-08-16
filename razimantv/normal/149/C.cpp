# include <cstdio>
# include <algorithm>
using namespace std;

struct two
{
    int i,s;
}a[100000],b[100000];

bool operator<(const two&t1,const two&t2)
{
    if(t1.s!=t2.s)return t1.s<t2.s;
    return t1.i<t2.i;
}

int main()
{
    int N,M;
    scanf("%d",&N);
    
    int asum=0,bsum=0,mmax=0;
    for(int i=0;i<N;i++)
    {
        if(i&1)
        {
            scanf("%d",&(a[i>>1].s));
            a[i>>1].i=i;
            asum+=a[i>>1].s;
            if(a[i>>1].s>mmax)mmax=a[i>>1].s;
        }
        else
        {
            scanf("%d",&(b[i>>1].s));
            b[i>>1].i=i;
            bsum+=b[i>>1].s;
            if(b[i>>1].s>mmax)mmax=b[i>>1].s;
        }
    }
    
    if(N&1)
    {
        M=N+1;
        a[N>>1].s=0;
        a[N>>1].i=N;
    }
    else M=N;
    
    int L=M>>1;
    sort(a,a+L);
    sort(b,b+L);
    
    two *A,*B;
    if(asum<bsum)
    {
        A=a;B=b;
    }
    else
    {
        A=b;B=a;
        swap(asum,bsum);
    }
    
    for(int i=0,j=L-1;bsum-asum>mmax;i++,j--)
    {
        swap(A[i].i,B[j].i);
        swap(A[i].s,B[j].s);
        int chng=B[j].s-A[i].s;
        bsum+=chng;asum-=chng;
    }
    
    int l1=L;
    for(int i=0;i<L;i++)
    {
        if(A[i].i==N)
        {
            A[i].i=A[L-1].i;
            A[i].s=A[L-1].s;
            l1--;
            break;
        }
    }
    printf("%d\n",l1);
    for(int i=0;i<l1;i++)
        printf("%d ",A[i].i+1);
    printf("\n");
    l1=L;
    for(int i=0;i<L;i++)
    {
        if(B[i].i==N)
        {
            B[i].i=B[L-1].i;
            B[i].s=B[L-1].s;
            l1--;
            break;
        }
    }
    printf("%d\n",l1);
    for(int i=0;i<l1;i++)
        printf("%d ",B[i].i+1);
    printf("\n");
}