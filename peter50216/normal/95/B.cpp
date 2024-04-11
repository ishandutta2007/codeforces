#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define N 100010
using namespace std;
string gen( int n, string s ) {
    string ret;
    while ( n-- ) ret+=s;
    return ret;
}
int d4[N],d7[N];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    d4[n]=d7[n]=n;
    for ( int i=n-1; i>=0; i-- ) {
        if ( s[i]!=4 ) d4[i]=i;
        else d4[i]=d4[i+1];
        if ( s[i]!=7 ) d7[i]=i;
        else d7[i]=d7[i+1];
    }
    if ( n%2==0 ) {
        string t1=gen(n/2,"7")+gen(n/2,"4");
        if ( t1<s ) {
            cout<<gen(n/2+1,"4")<<gen(n/2+1,"7")<<endl;
        } else {
            string now="";
            int flg=0,r4=n/2,r7=n/2;
            for ( int i=0; i<n; i++ ) {
                int tmt=0,p;
                if ( r4>0 ) {
                    if ( flg || s[i]<'4' ) tmt=1;
                    else if ( s[i]=='4' ) {
                        p=i+1;
                        while ( p<=n ) {
                            if ( p==n ) {
                                tmt=1;
                                break;
                            }
                            char c;
                            if ( p<=i+r7 ) c='7';
                            else c='4';
                            if ( s[p]<c ) tmt=1;
                            if ( s[p]!=c ) break;
p++;
                        }
                    }
                }
                if ( tmt ) now+="4",r4--;
                else now+="7",r7--;
                if ( now[i]>s[i] ) flg=1;
            }
            cout<<now<<endl;
        }
    } else {
        n++;
        cout<<gen(n/2,"4")<<gen(n/2,"7")<<endl;
    }
    return 0;
}