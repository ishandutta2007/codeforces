#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct po
{
    ll x;
    ll y;
    ll z;
    ll no;
};
ll a = 0, b, n, m, i, j, bar;
ll enterord[100001], exitord[100001], exitordbycar[100001];
int cmp(po a, po b)
{
    if (a.z != b.z)
        return (a.z < b.z);
    if (a.y != b.y)
        return (a.y < b.y);
    return (a.x < b.x);
}
int cmpy(po a, po b)
{
    if (a.y!=b.y) return (a.y > b.y);
    return (a.x<b.x);
}

int cmpx(po a, po b)
{
    return (a.x > b.x);
}

int srchy (po a, po b)
{
    return (a.y<b.y);
}
int srchx(po a, po b)
{
    return (a.x < b.x);
}
vector<po> space,clip;
po h;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> h.x >> h.y >> h.z;
        h.no = i;
        space.push_back(h);
    }
    sort(space.begin(), space.end(), cmp);
   // for (i=0;i<n;i++) cout<<space[i].x<<' '<<space[i].y<<' '<<space[i].z<<' '<<space[i].no<<endl;
    j = 0;
    a = -1;
    for (i = 1; i < n; i++)
    {
        if (space[i].z != space[i - 1].z)
        {
            a++;
            
            if (a)
                {
                    
                    h.z = space[j].z;
                    h.y= space[j-1].y;
                    auto it= lower_bound(space.begin() + j, space.begin() + i,h,srchy);
                    
                    sort(space.begin() + j, it, cmpy);
                    clip.clear();
                    clip.insert(clip.begin(),it,space.begin()+i);
                    space.erase(it, space.begin() + i);
                    space.insert(space.begin()+j,clip.begin(),clip.end());
                }
            j = i;
        }
    }
    a++;

    if (a)
    {

        h.z = space[j].z;
        h.y = space[j - 1].y;
        auto it = lower_bound(space.begin() + j, space.begin() + i, h, srchy) ;
        
        sort(space.begin() + j, it, cmpy);
        clip.clear();
        clip.insert(clip.begin(), it, space.begin() + i);
        space.erase(it, space.begin() + i);
        space.insert(space.begin() + j, clip.begin(), clip.end());
    }
    j = i;

    j = 0;
    a = -1;
    for (i = 1; i < n; i++)
    {
        if ((space[i].z != space[i - 1].z) or (space[i].y != space[i - 1].y))
        {
            a++;

            if (a)
            {

                h.z = space[j].z;
                h.y = space[j].y;
                h.x = space[j-1].x;
                auto it = lower_bound(space.begin() + j, space.begin() + i, h, srchx) ;
                
                sort(space.begin() + j, it, cmpx);
                clip.clear();
                clip.insert(clip.begin(), it, space.begin() + i);
                space.erase(it, space.begin() + i);
                space.insert(space.begin() + j, clip.begin(), clip.end());
            }
            j = i;
        }
    }
    a++;

    if (a)
    {

        h.z = space[j].z;
        h.y = space[j].y;
        h.x = space[j - 1].x;
        auto it = lower_bound(space.begin() + j, space.begin() + i, h, srchx) ;
        
        sort(space.begin() + j, it, cmpx);
        clip.clear();
        clip.insert(clip.begin(), it, space.begin() + i);
        space.erase(it, space.begin() + i);
        space.insert(space.begin() + j, clip.begin(), clip.end());
    }
    j = i;
    for (i = 0; i < n; i += 2)
        cout << space[i].no << ' ' << space[i + 1].no << endl;
}