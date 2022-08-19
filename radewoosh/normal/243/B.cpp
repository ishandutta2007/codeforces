#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int h, t;

vector <int> graf[100007];
pair <int,int> kra[100007];

int a, b;

vector <int> mni;
vector <int> wie;
vector <int> wsp;

vector < pair <int,int> > wek;

int main()
{
    scanf("%d%d%d%d", &n, &m, &h, &t);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &kra[i].first, &kra[i].second);
        graf[kra[i].first].push_back(kra[i].second);
        graf[kra[i].second].push_back(kra[i].first);
    }
    for (int i=1; i<=n; i++)
    {
        sort(graf[i].begin(), graf[i].end());
    }
    for (int g=1; g<=m; g++)
    {
        a=kra[g].first;
        b=kra[g].second;
        if (graf[b].size()<graf[a].size())
        {
            swap(a,b);
        }
        if (graf[a].size()<min(h,t)+1 || graf[b].size()<max(h,t)+1)
        {
            continue;
        }
        wek.clear();
        for (int i=0; i<graf[a].size(); i++)
        {
            if (graf[a][i]!=b)
            wek.push_back(make_pair(graf[a][i],1));
        }
        for (int i=0; i<graf[b].size(); i++)
        {
            if (graf[b][i]!=a)
            wek.push_back(make_pair(graf[b][i],2));
        }
        sort(wek.begin(), wek.end());
        mni.clear();
        wie.clear();
        wsp.clear();
        for (int i=0; i<wek.size(); i++)
        {
            if (i+1<wek.size() && wek[i].first==wek[i+1].first)
            {
                wsp.push_back(wek[i].first);
                i++;
                continue;
            }
            if (wek[i].second==1)
            {
                mni.push_back(wek[i].first);
                continue;
            }
            if (wek[i].second==2)
            {
                wie.push_back(wek[i].first);
                continue;
            }
        }
        /*if (a==4 && b==1)
        {
            printf("chuj\n\n\n");
            for (int i=0; i<wek.size(); i++)
            {
                printf("%d %d\n", wek[i].first, wek[i].second);
            }
            printf("\n");
            for (int i=0; i<mni.size(); i++)
            {
                printf("%d ", mni[i]);
            }
            printf("\n");
            for (int i=0; i<wie.size(); i++)
            {
                printf("%d ", wie[i]);
            }
            printf("\n");
            for (int i=0; i<wsp.size(); i++)
            {
                printf("%d ", wsp[i]);
            }
            printf("\n\n\n");
        }*/
        if (max(0, min(h, t)-(int)mni.size())+max(0, max(h, t)-(int)wie.size())>wsp.size())
        {
            continue;
        }
        /*printf("%d %d       %d %d     %d %d\n", max(0, min(h, t)-(int)mni.size()), max(0, max(h, t)-(int)wie.size()), min(h,t), (int)mni.size(), h, t);
        printf("dupa\n\n\n");
        for (int i=0; i<wek.size(); i++)
        {
            printf("%d %d\n", wek[i].first, wek[i].second);
        }
        printf("\n");
        for (int i=0; i<mni.size(); i++)
        {
            printf("%d ", mni[i]);
        }
        printf("\n");
        for (int i=0; i<wie.size(); i++)
        {
            printf("%d ", wie[i]);
        }
        printf("\n");
        for (int i=0; i<wsp.size(); i++)
        {
            printf("%d ", wsp[i]);
        }
        printf("\n\n\n");*/
        if (h>t)
        {
            swap(a, b);
            swap(mni, wie);
        }
        while(mni.size()<h)
        {
            mni.push_back(wsp.back());
            wsp.pop_back();
        }
        while(wie.size()<t)
        {
            wie.push_back(wsp.back());
            wsp.pop_back();
        }
        printf("YES\n");
        printf("%d %d\n", a, b);
        for (int i=0; i<h; i++)
        {
            printf("%d ", mni[i]);
        }
        printf("\n");
        for (int i=0; i<t; i++)
        {
            printf("%d ", wie[i]);
        }
        return 0;
    }
    printf("NO");
    return 0;
}