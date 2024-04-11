#include <bits/stdc++.h>

using namespace std;
struct SegmentTree{
    int n;
    int* lo;
    int* hi;
    long long* minn;
    long long* delta;
    SegmentTree(int nn)
    {
        n=nn;
        lo = new int[4*n+1];
        hi = new int[4*n+1];
        minn = new long long[4*n+1];
        delta = new long long[4*n+1];
        for(int i=0;i<4*n+1;i++)
        {
            minn[i]=0;
            delta[i]=0;
        }
        init(1,0,n-1);
    }
    void init(int i, int a, int b)
    {
        lo[i]=a;
        hi[i]=b;
        if(a==b)
            return;
        int m=(a+b)/2;
        init(2*i,a,m);
        init(2*i+1,m+1,b);
    }
    void prop(int i)
    {
        delta[2*i] += delta[i];
        delta[2*i+1] += delta[i];
        delta[i]=0;
    }
    void update(int i)
    {
        minn[i]=min(minn[2*i]+delta[2*i],minn[2*i+1]+delta[2*i+1]);
    }
    void increment(int i,int a, int b,int val)
    {
        if(b<lo[i] || a > hi[i])
            return;
        if(a <= lo[i] && hi[i] <= b)
        {
            delta[i]=(long long)delta[i] + val;
            return;
        }
        prop(i);
        increment(2*i,a,b,val);
        increment(2*i+1,a,b,val);
        update(i);
    }
    long long minimum(int i,int a, int b)
    {
        long long inf=100000000000000;
        if(b<lo[i] || a > hi[i])
            return inf;
        if(a <= lo[i] && hi[i] <= b)
        {
            return minn[i]+delta[i];
        }
        prop(i);
        long long minL=minimum(2*i,a,b);
        long long minR=minimum(2*i+1,a,b);
        update(i);
        return min(minL,minR);
    }
};
int main()
{
    int n;
    scanf("%i",&n);
    SegmentTree s(n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        s.increment(1,i,i,a);
        //printf("  i:%i  a:%i  min:%lld\n",i,a,s.minimum(1,i,i));
    }
    int m;
    scanf("%i",&m);
    string niz;
    getline(cin,niz);
    for(int i=0;i<m;i++)
    {
        string niz;
        getline(cin,niz);
        niz.push_back('A');
        /*for(int i=0;i<niz.size();i++)
        {
            printf("%c",niz[i]);
        }
        printf("\n");*/
        int a=0,b=0,v=0;
        int tr=0;
        int lol=1000000;
        while('0'<=niz[tr]&&niz[tr]<='9')
        {
            a+=(niz[tr]-'0')*lol;
            lol/=10;
            tr++;
        }
        a/=lol*10;
        tr++;
        lol=1000000;
        while('0'<=niz[tr]&&niz[tr]<='9')
        {
            b+=(niz[tr]-'0')*lol;
            lol/=10;
            tr++;
        }
        b/=lol*10;
        //printf("ab: %i %i\n",a,b);
        if(niz[tr]=='A')
        {
            if(a>b)
            {
                cout << min(s.minimum(1,a,n-1),s.minimum(1,0,b)) << endl;
            }
            else
            {
                cout << s.minimum(1,a,b) << endl;
            }
        }
        else
        {
            tr++;
            lol=10000000;
            int t=1;
            if(niz[tr]=='-')
            {
                t=-1;
                tr++;
            }
            while('0'<=niz[tr]&&niz[tr]<='9')
            {
                v+=(niz[tr]-'0')*lol*t;
                lol/=10;
                tr++;
            }
            v/=lol*10;
            //printf("V: %i\n",v);
            if(a>b)
            {
                s.increment(1,a,n-1,v);
                s.increment(1,0,b,v);
            }
            else
            {
                s.increment(1,a,b,v);
            }
        }
    }
    return 0;
}