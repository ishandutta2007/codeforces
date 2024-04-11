#include <cstdio>
#include <set>

using namespace std;

int a,b,c,n;
multiset<int> dats;

int max(int a,int b){ return a>b?a:b; }

void try_to_erase(int x){
    auto it=dats.upper_bound(x);
    if(it!=dats.begin()){
        --it;
        dats.erase(it);
    }
}

bool leq_exist(int x){ return dats.upper_bound(x) != dats.begin(); }

void swap(int& a,int& b){ int tmp=a; a=b; b=tmp; }

int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&c);
    
    
    int i, buf;
    for(i=0;i<n;++i) scanf("%d",&buf), dats.insert(buf);
    
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    
    auto it_last = dats.end(); --it_last;
    int ans=0;
    if(*it_last > a+b+c){
        puts("-1"); return 0;
    }
    
    while(dats.size()){
        auto it=dats.end(); --it;
        if(*it > (b+c)){                   // a+b+c
            dats.erase(it);
        } else if(*it > (a+c)){            // b+c. use a too
            dats.erase(it);
            try_to_erase(a);
        } else if(*it > max(c,a+b)){       // a+c. use b too
            dats.erase(it);
            try_to_erase(b);
        } else {
            if(c>a+b){                     // use c.
                dats.erase(it);
                if(leq_exist(b)){
                    try_to_erase(b);
                    try_to_erase(a);
                } else {
                    try_to_erase(a+b);
                }
            } else {
                if(*it > c){
                    dats.erase(it);
                    try_to_erase(c);
                } else {
                    dats.erase(it);
                    if(leq_exist(b)){
                        try_to_erase(b);
                        try_to_erase(a);
                    } else {
                        try_to_erase(a+b);
                    }
                }
            }
        }
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}