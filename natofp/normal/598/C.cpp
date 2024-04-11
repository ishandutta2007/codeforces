#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct vec
{
    long long int x;
    long long int y;
    int n;
};

int get(vec a)
{
    if(a.x>0 && a.y>=0) return 1;
    if((a.x==0 && a.y>0) || a.y>0) return 2;
    if(a.x<0 && a.y<=0) return 3;
    return 4;
}

struct cost
{
    long long int val1;
    long long int val2;
    bool sign;
};

long long int gcd(long long int a,long long int b)
{
    while(b)
    {
        long long int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

bool czy(long long int a1,long long int a2,long long int b1,long long int b2)
{
    vector<int> wynik1(36,0);
    vector<int> wynik2(36,0);
    int k=0;
    while(a1>0)
    {
        long long int akt=a1%10;
        a1/=10;
        long long int t=akt*b2;
        int k2=0;
        while(t>0)
        {
            
            int n=t%10; t/=10;
            wynik1[k+k2]+=n;
            k2++;
        }
        k++;
    }
    k=0;
    while(a2>0)
    {
        
        long long int akt=a2%10;
        a2/=10;
        long long int t=akt*b1;
        int k2=0;
        while(t>0)
        {
            int n=t%10; t/=10;

            wynik2[k+k2]+=n;
            k2++;
        }
        k++;
    }
    for(int i=0;i<35;i++)
    {
        if(wynik1[i]>=10) {int t=wynik1[i]/10; wynik1[i]%=10; wynik1[i+1]+=t;}
        if(wynik2[i]>=10) {int t=wynik2[i]/10; wynik2[i]%=10; wynik2[i+1]+=t;}
    }
    for(int i=35;i>=0;i--)
    {
        if(wynik1[i]>wynik2[i]) return true;
        if(wynik1[i]<wynik2[i]) return false;
    }
    return false;

}

bool czy2(long long int a1,long long int a2,long long int b1,long long int b2)
{
    return a1*b2>a2*b1;
}
bool por(vec a,vec b)
{
    int x,y;
    x=get(a); y=get(b);
    if(x!=y) return x<y;
    cost i,j;
    i.val1=a.x*a.x;
    i.val2=a.x*a.x+a.y*a.y;
    j.val1=b.x*b.x;
    j.val2=b.x*b.x+b.y*b.y;
    if(x==1)
    {
        return czy2(i.val1,i.val2,j.val1,j.val2);
    }
    if(x==2)
    {
        return !czy2(i.val1,i.val2,j.val1,j.val2);
    }
    if(x==3)
    {
        return czy2(i.val1,i.val2,j.val1,j.val2);
    }
    if(x==4)
    {
        return !czy2(i.val1,i.val2,j.val1,j.val2);
    }
}

cost daj(vec a,vec b)
{
    cost ans;
    if(a.x*b.x+a.y*b.y<0) ans.sign=false;
    else ans.sign=true;
    ans.val1=(a.x*b.x+a.y*b.y)*(a.x*b.x+a.y*b.y);
    ans.val2=(a.x*a.x+a.y*a.y)*(b.x*b.x+b.y*b.y);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n; cin>>n;
    vec * a=new vec[n];
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        vec nowy;
        nowy.x=x;
        nowy.y=y;
        nowy.n=i;
        a[i-1]=nowy;

    }
    sort(a,a+n,por);
    int idx;
    idx=0;
    cost best=daj(a[0],a[1]);
    for(int i=0;i<n;i++)
    {
        cost xd=daj(a[i],a[(i+1)%n]);
        if(best.sign==false)
        {
            if(xd.sign==true) {best=xd; idx=i; continue;}
            if(czy(best.val1,best.val2,xd.val1,xd.val2)==true) {best=xd; idx=i; continue;}
        }
        else
        {
            if(xd.sign==false) continue;
            else if(czy(best.val1,best.val2,xd.val1,xd.val2)==false) {best=xd; idx=i;}
        }
    }
    cout<<a[idx].n<<" "<<a[(idx+1)%n].n;
    return 0;
}