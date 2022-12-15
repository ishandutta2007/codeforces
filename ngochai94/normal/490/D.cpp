#include <bits/stdc++.h>
using namespace std;

long long a1,b1,a2,b2,s13,s23,s12,s22,m;
long long s1,s2,tmp;

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    m=0;
    cin>>a1>>b1>>a2>>b2;
    s1=a1*b1;
    s2=a2*b2;
    //cout<<s1<<endl<<s2<<endl;
    tmp=s1;
    s13=0;
    s23=0;
    while (tmp%3==0)
    {
        s13++;
        //cout<<tmp<<endl;
        tmp/=3;
    }
    tmp=s2;
    //cout<<s13<<endl<<s23;
    while (tmp%3==0)
    {
        s23++;
        //cout<<tmp<<endl;
        tmp/=3;
        //cout<<tmp;
    }
    //cout<<s13<<s23;
    if (s13>=s23)
    {
        s13-=s23;
        for (int i=0;i<s13;i++)
        {
            s1/=3;
            s1*=2;
        }
        s12=0;
        //cout<<'a';
        //cout<<s1;
        while (s1%2==0)
        {
            s12++;
            s1>>=1;
            //cout<<s1<<endl;
        }
        s22=0;
        //cout<<s2;
        while (s2%2==0)
        {
            s22++;
            s2>>=1;
        }
        if (s1!=s2)
        {
            cout<<-1;
            return 0;
        }
        while(s13--)
        {
            if(a1%3==0) {a1/=3;a1*=2;m++;}
            else {b1/=3;b1*=2;m++;}
        }
        //cout<<'a';
        if (s12>=s22)
        {
            s12-=s22;
            while (s12--)
            {
                if(a1%2==0) a1>>=1;
                else b1>>=1;
                m++;
            }
        }
        else
        {
            s22-=s12;
            while (s22--)
            {
                if(a2%2==0) a2>>=1;
                else b2>>=1;
                m++;
            }
        }
        cout<<m<<endl<<a1<<' '<<b1<<endl<<a2<<' '<<b2;
    }
    else
    {
        s23-=s13;
        while (s23--)
        {
            s2/=3;
            s2*=2;
            if(a2%3==0) {a2/=3;a2*=2;}
            else {b2/=3;b2*=2;}
            m++;
        }
        s12=0;
        s22=0;
        while (s2%2==0)
        {
            s2>>=1;
            s22++;
        }
        while (s1%2==0)
        {
            s1>>=1;
            s12++;
        }
        if(s1!=s2)
        {
            cout<<-1;
            return 0;
        }
        if(s12>=s22)
        {
            s12-=s22;
            while(s12--)
            {
                if(a1%2==0) a1>>=1;
                else b1>>=1;
                m++;
            }
        }
        else
        {
            s22-=s12;
            while(s22--)
            {
                if(a2%2==0) a2>>=1;
                else b2>>=1;
                m++;
            }
        }
        cout<<m<<endl<<a1<<' '<<b1<<endl<<a2<<' '<<b2;
    }
    return 0;
}