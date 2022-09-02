#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define all(a) (a.begin(),a.end())

#define taskname "A"

using namespace std;

typedef long long int64;
typedef long double ld;

bool check(char c){
    return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c<='9' && c>='0') || (c=='_');
}

bool check_word(string s){
    int n=s.size();
    //cerr<<s<<endl;
    //cerr<<n<<endl;
    if (n<1 || n>16){
        printf("NO\n");
        exit(0);
    }
    for (int i=0;i<n;i++){
        if (!check(s[i]))
        {
            printf("NO\n");
            exit(0);
        }       
    }
    return true;
}

int main(){
    #ifdef LOCAL
        freopen(taskname".in","r",stdin);
        freopen(taskname".out","w",stdout);
    #endif
    int len=0;
    char c;
    string s="";
	string st;
	getline(cin,st);
	int ptr=0;

	//cerr<<st<<endl;
	
    for (;;){
        if (ptr!=st.size())
        {
			c=st[ptr];
			++ptr;
			//cerr<<c<<endl;
			if (c=='@')
				break;
			s+=c;
        }
        else{
			printf("NO\n");
			return 0;
		}
    }
    
    
    check_word(s);
    s="";
    
    for (;;){
        if (ptr!=st.size()){
			c=st[ptr];
			++ptr;
			len++;
            if (c=='.')
            {
                check_word(s);
                s="";
            }
            else if (c=='/'){
				//cerr<<len<<endl;
                if (len>33)
                {
                    printf("NO\n");
                    return 0;
                }
                check_word(s);
				s="";
				for (;ptr<st.size();++ptr)
					s+=st[ptr];
                check_word(s);
                printf("YES\n");
                return 0;
            }
            else
                s+=c;
            if (len>32)
            {
                printf("NO\n");
                return 0;
            }
        }
        else
        {
			//cerr<<s<<endl;
            if (len>32)
            {
                printf("NO\n");
                return 0;
            }   
          //  cerr<<s<<endl;
            check_word(s);
            printf("YES\n");
            return 0;
        }
    }
    
    
    
    return 0;
}