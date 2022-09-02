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

typedef long long ll;
typedef long double ld;

struct myset{
    multiset<int> s;
    int add;

    int get(){
        if (!s.size())
            return (1<<30);
        return *s.begin()+add;
    }

    void insert(int x){
        s.insert(x - add);
    }

    void erase(int x){
        assert(s.find(x - add) != s.end());
        s.erase(s.find(x-add));
    }

    void addval(int dlt){
        add += dlt;
    }

    void print(){
        for (multiset<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
            cerr << *iter +add<<" ";
        cerr << endl;
    }

};

const int MAXN = 110000;

int rid[MAXN];
int a[MAXN];
int n;

myset up,down;


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        rid[x] = i;
    }

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        a[i] = rid[a[i]];
       // cerr << a[i] <<" ";
    }
    //cerr << endl;


    for (int i = 0; i < n; i++){
        if (i <= a[i]){
            up.insert(a[i] - i);
        }
        else {
            down.insert(i - a[i]);
        }
    }

    /*cerr <<"UP: ";up.print();
    cerr <<"DO: ";down.print(); 
    cerr << endl;*/ 



    for (int i = 0; i < n; i++){
        //cerr << a[i] << endl;
        printf("%d\n",min(up.get(),down.get()));

        up.erase(a[i]);
        down.insert(n - a[i]);
        //cerr <<"!"<<endl;

        up.addval(1);
        down.addval(-1);      
        //cerr <<"!"<<endl;                                      

        for (;down.get() == 0;){
           //cerr <<"!"<<endl;
           down.erase(0);
           up.insert(0);
        }
        
        /*cerr <<"UP: ";up.print();
        cerr <<"DO: ";down.print(); 
        cerr << endl; */
    }
              
    return 0;
}