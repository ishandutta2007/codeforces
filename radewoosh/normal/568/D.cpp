#include <bits/stdc++.h>
using namespace std;

int n, k;

long long a[1000007];
long long b[1000007];
long long c[1000007];

vector <int> wek;
vector < pair <int,int> > odp;

pair <int,int> najl;
int ileb;

int ilej;


int rek(vector <int> roz, int l)
{
    //for (int i=0; i<roz.size(); i++)
    //{
    //    printf("%d ", roz[i]);
    //}
    //printf("\n");
    if (roz.empty())
    {
        return 1;
    }
    if (!l)
    {
        return 0;
    }
    if (l>=roz.size())
    {
        for (int i=0; i<roz.size(); i++)
        odp.push_back(make_pair(roz[i], -1));
        return 1;
    }
    if (roz.size()<26)
    {
        long long xlicz, xmian;
        long long ylicz, ymian;
        random_shuffle(roz.begin(), roz.end());
        int v, u, o;
        vector <int> dopch;
        for (int i=0; i<min((int) roz.size(), 6); i++)
        {
            for (int j=i+1; j<min((int) roz.size(), 6); j++)
            {
                v=roz[i];
                u=roz[j];

                if (a[v]*b[u]==a[u]*b[v])
                continue;
                //printf("ryzyk w %d %d\n", v, u);
                dopch.clear();

                xlicz=-c[v]*b[u]+c[u]*b[v];
                xmian=a[v]*b[u]-a[u]*b[v];

                ylicz=-c[u]*a[v]+c[v]*a[u];
                ymian=a[v]*b[u]-a[u]*b[v];

                //printf("%lld %lld   %lld %lld\n", xlicz, xmian, ylicz, ymian);

                for (int p=0; p<roz.size(); p++)
                {
                    o=roz[p];
                    if (a[o]*xlicz*ymian+b[o]*ylicz*xmian+c[o]*ymian*xmian)
                    {
                        dopch.push_back(o);
                    }
                }
                odp.push_back(make_pair(v, u));
                if (rek(dopch, l-1))
                return 1;
                odp.pop_back();
            }
        }
    }
    else
    {
        long long xlicz, xmian;
        long long ylicz, ymian;
        random_shuffle(roz.begin(), roz.end());
        int v, u, o;
        vector <int> dopch;
        ileb=0;
        for (int h=1; h<=100; h++)
        {
            v=(rand()%roz.size());
            u=(rand()%(roz.size()-1));
            if (u==v)
            u++;
            v=roz[v];
            u=roz[u];

            if (a[v]*b[u]==a[u]*b[v])
            continue;

            ilej=0;

            xlicz=-c[v]*b[u]+c[u]*b[v];
            xmian=a[v]*b[u]-a[u]*b[v];

            ylicz=-c[u]*a[v]+c[v]*a[u];
            ymian=a[v]*b[u]-a[u]*b[v];

            //printf("%lld %lld   %lld %lld\n", xlicz, xmian, ylicz, ymian);

            for (int p=0; p<roz.size(); p++)
            {
                o=roz[p];
                if (!(a[o]*xlicz*ymian+b[o]*ylicz*xmian+c[o]*ymian*xmian))
                {
                    ilej++;
                }
            }
            if (ilej>ileb)
            {
                ileb=ilej;
                najl=make_pair(v, u);
            }
        }

        if (!ileb)
        return 0;

        v=najl.first;
        u=najl.second;

        xlicz=-c[v]*b[u]+c[u]*b[v];
        xmian=a[v]*b[u]-a[u]*b[v];

        ylicz=-c[u]*a[v]+c[v]*a[u];
        ymian=a[v]*b[u]-a[u]*b[v];

        //printf("%lld %lld   %lld %lld\n", xlicz, xmian, ylicz, ymian);

        for (int p=0; p<roz.size(); p++)
        {
            o=roz[p];
            if (a[o]*xlicz*ymian+b[o]*ylicz*xmian+c[o]*ymian*xmian)
            {
                dopch.push_back(o);
            }
        }
        odp.push_back(make_pair(v, u));
        if (rek(dopch, l-1))
        return 1;
        odp.pop_back();
    }
    return 0;
}

int main()
{
    srand(time(0));
    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++)
    {
        wek.push_back(i);
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    }
    if (!rek(wek, k))
    {
        printf("NO");
        return 0;
    }
    printf("YES\n%d\n", (int) odp.size());
    for (int i=0; i<odp.size(); i++)
    {
        printf("%d %d\n", odp[i].first, odp[i].second);
    }
    return 0;
}