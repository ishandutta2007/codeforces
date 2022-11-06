#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;

char buf[200010];
char a[200010];
int n, t;
int l;
int digp;

set<int> s;

int main()
{
    scanf("%d%d",&n,&t);
    scanf("%s", buf);
    for(int i=n-1; 0<=i; --i){
        if(buf[i] == '.'){
            digp = n-1-i; continue;
        }
        a[l++]=buf[i];
    }
    for(int i=l; i<=200005; ++i) a[i]='0';

    for(int i=0; a[i]; ++i){
        if(a[i]=='.') continue;
        if(a[i] >= '5' && i<digp) s.insert(i);
    }
    int clear_until = 0;
    for(;t--;){
        if(s.empty()) break;
        int pt = *--s.end();
        s.clear();
        clear_until = max(clear_until, pt);
        a[pt] = '0';
        for(int i=pt+1; a[i]; ++i){
            if(a[i] == '9'){
                a[i]='0';
            } else {
                ++a[i];
                if(a[i] >= '5' && i<digp) s.insert(i);
                break;
            }
        }
    }
    for(int i=0; i<clear_until; ++i) a[i]='0';
    int last_exist = digp;
    for(int i=0; i<digp; ++i) if(a[i] != '0'){
        last_exist = min(last_exist, i);
    }
    bool started = false;
    for(int i=200005; last_exist<=i; --i){
        if(a[i] > '0'){
            started = true;
        }
        if(started) putchar(a[i]);
        if(i == digp){
            if(last_exist < i){
                if(!started) putchar('0');
                putchar('.');
                started=true;
            }
            else {
                break;
            }
        }
    }
    return 0;
}