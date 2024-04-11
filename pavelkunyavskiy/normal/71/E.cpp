#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

const string names[103] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl",
                            "Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se",
                            "Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb",
                            "Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er",
                            "Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At",
                            "Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No",
                            "Lr"};

map<string,int> number;

int a[20];
int sum[1<<20];
int t[20][1<<20];
int b[20];
int k,n;

vector<int> masks[110];


bool calc(int last,int mask){
    int& ans = t[last][mask];
    if (last == 0)
        return ans = (mask == 0);
    if (mask == 0)
        return ans = false;
    if (ans != -1)
        return ans;
    for (int i=0,sz=masks[b[last-1]].size();i<sz;i++)
        if (!((~mask) & (masks[b[last-1]][i])))
            if (calc(last-1,mask^(masks[b[last-1]][i])))
                return ans = true;
    return ans = false;
}

void oneprint(int mask,int to){
    bool q=false;
    for (int i=0;i<n;i++)
        if (mask & (1<<i)){
            if (q)
                printf("+");
            else
                q=true;
            printf("%s",names[a[i]-1].data());
        }
    printf("->");
    printf("%s\n",names[b[to]-1].data());
}

void print(int last,int mask){
    if (last == 0)
        return;
    for (int i=0,sz=masks[b[last-1]].size();i<sz;i++)
        if (!((~mask) & (masks[b[last-1]][i])))
            if (calc(last-1,mask^(masks[b[last-1]][i]))){
                oneprint(masks[b[last-1]][i],last-1);
                print(last-1,mask ^ masks[b[last-1]][i]);
                return;
            }
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    for (int i=0;i<103;i++)
        number[names[i]] = i+1;
    
    cin>>n>>k;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i] = number[s];
    }
    
    for (int i=0;i<k;i++){
        string s;
        cin>>s;
        b[i] = number[s];
    }
    
    for (int i=0;i<n;i++)
        sum[1<<i] = a[i];
    for (int i=0;i<(1<<n);i++)
        sum[i] = sum[i&(i-1)] + sum[i&(~(i-1))];
    
    for (int i=0;i<(1<<n);i++)
        if (sum[i] <= 100)
            masks[sum[i]].pb(i);
    
    memset(t,-1,sizeof(t));
    if (!calc(k,(1<<n)-1))
        printf("NO\n");
    else{
        printf("YES\n");
        print(k,(1<<n)-1);
    }
    return 0;
}