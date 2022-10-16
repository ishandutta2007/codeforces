#include <bits/stdc++.h>

using namespace std;
void spoj(vector<int> a)
{
    if(a.size()<=1)
    {
        return;
    }
    int kraj=a[a.size()-1];
    for(int i=0;i<a.size()-1;i++)
    {
        printf("1 %i %i\n",a[i],kraj);
    }
}
void spoj2(vector<int> a,int x)
{
    if(a.size()<=2)
    {
        return;
    }
    int kraj=a[a.size()-1];
    if(kraj==x)
    {
        kraj=a[a.size()-2];
    }
    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i]!=x&&a[i]!=kraj)
        printf("1 %i %i\n",a[i],kraj);
    }
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> poz[3];
    int maxx=-1;
    int pozi;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%i",&a);
        if(a<0&&(maxx==-1||maxx<a))
        {
            maxx=a;
            pozi=i;
        }
        if(a<0)
            poz[1].push_back(i);
        if(a==0)
            poz[0].push_back(i);
        if(a>0)
            poz[2].push_back(i);
    }
    if(poz[0].size()>0)
    {
        int poz_nule=poz[0][poz[0].size()-1];
        spoj(poz[0]);
        spoj(poz[2]);
        if(poz[1].size()%2==1)
        {
            printf("1 %i %i\n",pozi,poz_nule);
            if(poz[2].size()>0||poz[1].size()>1)
            printf("2 %i\n",poz_nule);
            if(poz[1].size()==1)
            {
                return 0;
            }
            spoj2(poz[1],pozi);
            if(poz[1][poz[1].size()-1]==pozi)
            {
                if(poz[2].size()>0&&poz[1].size()>1)
                printf("1 %i %i\n",poz[2][poz[2].size()-1],poz[1][poz[1].size()-2]);
            }
            else
            {
                if(poz[2].size()>0&&poz[1].size()>1)
                printf("1 %i %i\n",poz[2][poz[2].size()-1],poz[1][poz[1].size()-1]);
            }
        }
        else
        {
            spoj(poz[1]);
            if(poz[2].size()>0||poz[1].size()>1)
            printf("2 %i\n",poz_nule);
            if(poz[2].size()>0&&poz[1].size()>1)
            printf("1 %i %i\n",poz[2][poz[2].size()-1],poz[1][poz[1].size()-1]);
        }
    }
    else
    {
        spoj(poz[2]);
        if(poz[1].size()%2==1)
        {
            if(poz[2].size()>0||poz[1].size()>1)
            printf("2 %i\n",pozi);
            spoj2(poz[1],pozi);
            if(poz[1][poz[1].size()-1]==pozi)
            {
                if(poz[2].size()>0&&poz[1].size()>1)
                    printf("1 %i %i\n",poz[2][poz[2].size()-1],poz[1][poz[1].size()-2]);
            }
            else
            {
                if(poz[2].size()>0&&poz[1].size()>1)
                    printf("1 %i %i\n",poz[2][poz[2].size()-1],poz[1][poz[1].size()-1]);
            }
        }
        else
        {
            spoj(poz[1]);
            if(poz[2].size()>0&&poz[1].size()>1)
            printf("1 %i %i\n",poz[2][poz[2].size()-1],poz[1][poz[1].size()-1]);
        }
    }
    return 0;
}