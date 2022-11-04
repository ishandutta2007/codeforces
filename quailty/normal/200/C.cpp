#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
struct Team
{
    string name;
    int scored_points;
    int scored_goals;
    int missed_goals;
    int played_games;
    bool operator < (const Team &t)const
    {
        if(scored_points!=t.scored_points)
            return scored_points>t.scored_points;
        else if(scored_goals-missed_goals!=t.scored_goals-t.missed_goals)
            return scored_goals-missed_goals>t.scored_goals-t.missed_goals;
        else if(scored_goals!=t.scored_goals)
            return scored_goals>t.scored_goals;
        else return name<t.name;
    }
}t[15];
map<string,int>mp;
int getId(string s)
{
    if(!mp[s])t[mp[s]=(int)mp.size()].name=s;
    return mp[s];
}
bool check(int x,int y)
{
    int other=0;
    for(int i=1;i<=4;i++)
        if(t[i].played_games<3)
            other=i;
    t[getId("BERLAND")].scored_goals+=x;
    t[getId("BERLAND")].missed_goals+=y;
    t[other].scored_goals+=y;
    t[other].missed_goals+=x;
    vector<Team>v;
    for(int i=1;i<=4;i++)
        v.push_back(t[i]);
    t[getId("BERLAND")].scored_goals-=x;
    t[getId("BERLAND")].missed_goals-=y;
    t[other].scored_goals-=y;
    t[other].missed_goals-=x;
    sort(v.begin(),v.end());
    return v[0].name=="BERLAND" || v[1].name=="BERLAND";
}
char buff[25];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<5;i++)
    {
        scanf("%s",buff);
        int u=getId(buff);
        scanf("%s",buff);
        int v=getId(buff);
        int a,b;
        scanf("%d:%d",&a,&b);
        t[u].scored_goals+=a;
        t[u].missed_goals+=b;
        t[u].played_games+=1;
        t[v].scored_goals+=b;
        t[v].missed_goals+=a;
        t[v].played_games+=1;
        if(a>b)t[u].scored_points+=3;
        else if(a<b)t[v].scored_points+=3;
        else
        {
            t[u].scored_points+=1;
            t[v].scored_points+=1;
        }
    }
    t[getId("BERLAND")].scored_points+=3;
    t[getId("BERLAND")].played_games+=1;
    int resx=100,resy=0,isok=0;
    for(int i=0;i<100;i++)
        for(int j=0;j<i;j++)
            if(check(i,j) && (i-j<resx-resy || (i-j==resx-resy && j<resy)))
                resx=i,resy=j,isok=1;
    if(isok)printf("%d:%d",resx,resy);
    else printf("IMPOSSIBLE");
    return 0;
}