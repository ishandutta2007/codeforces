# include <cstdio>

int main()
{
    double vp,vd,t,f,c;
    scanf("%lf%lf%lf%lf%lf",&vp,&vd,&t,&f,&c);
    
    if(vd<=vp)
    {
        printf("0\n");
        return 0;
    }
    double st=t*vp;
    int bj=0;
    while(1)
    {
        double nextmeet=st/(vd-vp);
        st=st+nextmeet*vp;
        if(st+1e-8>c)break;
        bj++;
        st=st+(f+st/vd)*vp;
    }
    printf("%d\n",bj);
}