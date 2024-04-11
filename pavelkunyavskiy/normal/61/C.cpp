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

int a,b;

int64 convertto10(string c,int base){
    int64 res=0;
    for (int i=0;i<c.size();i++){
        int cif=0;
        if ('0'<= c[i] && c[i]<='9')
            cif=c[i]-'0';
        else
            cif=c[i]-'A'+10;
        res=res*base+cif;
    }
    return res;
}

string convertfrom10(int64 c,int base){
    if (c==0)
        return "0";
    string res="";
    for (;c;c/=base){
        int cif=c%base;
        if (cif<=9)
            res=char('0'+cif)+res;
        else
            res=char('A'+cif-10)+res;
    }
    return res;
}


string converttorim(int64 c){   
    if (c==0)
        return "";
    if (c>=1000)
        return "M" +converttorim(c-1000);
    if (c>=900)
        return "CM"+converttorim(c-900);
    if (c>=500)
        return "D" +converttorim(c-500);
    if (c>=400)
        return "CD"+converttorim(c-400);
    if (c>=100)
        return "C" +converttorim(c-100);

    if (c>=90)
        return "XC"+converttorim(c-90);
    if (c>=50)
        return "L"+converttorim(c-50);
    if (c>=40)
        return "XL"+converttorim(c-40);
    if (c>=10)
        return "X"+converttorim(c-10);

    if (c == 9)
        return "IX";
    if (c >= 5)
        return "V"+converttorim(c-5);
    if (c == 4)
        return "IV";
    return "I"+converttorim(c-1);       
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int t=scanf("%d %d",&a,&b);
    if (t == 2){
        string c;
        cin>>c;
        cout<< convertfrom10(convertto10(c,a),b) << endl;
        return 0;
    }
    scanf(" R ");
    string c;
    cin>>c;
    cout<< converttorim(convertto10(c,a)) << endl;  
    return 0;
}