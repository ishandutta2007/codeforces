#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

using namespace std;

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define LL long long
#define inf INT_MAX/2
#define mod 1000000007
#define PI 2.0*acos(0.0)
#define vsort(v) sort(v.begin(),v.end())
char pp[36],pr[2001];
int on[2001];
struct trie
{
    trie *nxt[26];
    trie()
    {
        memset(nxt,NULL,sizeof nxt);
    }
};
void insert(char *ps,trie *ob)
{
    //cout<<ps[0]<<endl;
    if(ps[0]=='\0')
    {
        return;
    }
    if(ob->nxt[ps[0]-'a']==NULL)ob->nxt[ps[0]-'a']=new trie();
    insert(ps+1,ob->nxt[ps[0]-'a']);
}
int cnt=0;
void travarse(trie *ob)
{
    cnt++;
    for(int x=0;x<26;x++)
    {
        if(ob->nxt[x]!=NULL)travarse(ob->nxt[x]);
    }
}
main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>pr>>pp;
    cin>>a;
    b=strlen(pr);
    for(x=1;x<=b;x++)
    {
        on[x]=1-(pp[pr[x-1]-'a']-'0');
        on[x]+=on[x-1];
    }
    on[b+1]=on[b];
    c=0;
    trie *tr=new trie();
    for(x=1;x<=b;x++)
    {
        char pq[2001];
        for(y=x;y<=b;y++)
        {
            pq[y-x]=pr[y-1];
            d=on[y]-on[x-1];
            e=on[y+1]-on[x-1];
            if((d==a && e>a) || (y==b&& d<=a))
            {
                //cout<<s<<endl;
                pq[y-x+1]='\0';
                //cout<<pq<<endl;
                insert(pq,tr);
            }
        }
    }
    travarse(tr);
    cout<<cnt-1<<endl;
}