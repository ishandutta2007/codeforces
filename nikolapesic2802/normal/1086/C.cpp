#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a))
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
void test()
{
    int k;
    cin >> k;
    string s1,a1,b1;
    cin >> s1 >> a1 >> b1;
    int temp[k];
    bool taken[k];
    for(int i=0;i<k;i++)
        temp[i]=-1,taken[i]=false;
    int n=s1.size();
    vector<int> s(n),a(n),b(n);
    for(int i=0;i<n;i++)
    {
        s[i]=s1[i]-'a';
        a[i]=a1[i]-'a';
        b[i]=b1[i]-'a';
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i])
        {
            if((temp[s[i]]!=-1&&temp[s[i]]!=a[i])||(taken[a[i]]&&temp[s[i]]!=a[i]))
            {
                printf("NO\n");
                return;
            }
            temp[s[i]]=a[i];
            taken[a[i]]=true;
        }
        else
        {
            for(int d=a[i]+1;d<b[i];d++)
            {
                if((temp[s[i]]==-1&&taken[d]==false)||temp[s[i]]==d)
                {
                    temp[s[i]]=d;
                    taken[d]=true;
                    printf("YES\n");
                    for(int w=0;w<k;w++)
                    {
                        if(temp[w]!=-1)
                            printf("%c",temp[w]+'a');
                        else
                        {
                            for(int j=0;j<k;j++)
                            {
                                if(!taken[j])
                                {
                                    taken[j]=true;
                                    printf("%c",j+'a');
                                    break;
                                }
                            }
                        }
                    }
                    printf("\n");
                    return;
                }
            }
            int t1[k];
                    bool t2[k];
                    for(int das=0;das<k;das++)
                    {
                        t1[das]=temp[das];
                        t2[das]=taken[das];
                    }
            bool ne=false;
            if((temp[s[i]]==-1&&taken[a[i]]==false)||temp[s[i]]==a[i])
            {
                temp[s[i]]=a[i];
                taken[a[i]]=true;
            for(int j=i+1;j<n;j++)
            {
                if(temp[s[j]]==-1)
                {

                    //printf("%i %i %i\n",a[i],b[i],s[i]);
                    for(int d=a[j]+1;d<k;d++)
                    {
                        if(!taken[d])
                        {
                            temp[s[j]]=d;
                            taken[d]=true;
                            printf("YES\n");
                            for(int w=0;w<k;w++)
                            {
                                if(temp[w]!=-1)
                                    printf("%c",temp[w]+'a');
                                else
                                {
                                    for(int j1=0;j1<k;j1++)
                                    {
                                        if(!taken[j1])
                                        {
                                            taken[j1]=true;
                                            printf("%c",j1+'a');
                                            break;
                                        }
                                    }
                                }
                            }
                            printf("\n");
                            return;
                        }
                    }
                    if(taken[a[j]])
                    {
                        ne=true;
                        break;
                        //printf("NO\n");
                        //return;
                    }
                    else
                    {
                        temp[s[j]]=a[j];
                        taken[a[j]]=true;
                    }
                }
                else
                {
                    if(temp[s[j]]>a[j])
                    {
                        printf("YES\n");
                            for(int w=0;w<k;w++)
                            {
                                if(temp[w]!=-1)
                                    printf("%c",temp[w]+'a');
                                else
                                {
                                    for(int j1=0;j1<k;j1++)
                                    {
                                        if(!taken[j1])
                                        {
                                            taken[j1]=true;
                                            printf("%c",j1+'a');
                                            break;
                                        }
                                    }
                                }
                            }
                            printf("\n");
                            return;
                    }
                    if(temp[s[j]]<a[j])
                    {
                        ne=true;
                        break;
                    }
                }
            }
            }
            else
            {
                ne=true;
            }
            if(ne==false)
            {
                printf("YES\n");
                            for(int w=0;w<k;w++)
                            {
                                if(temp[w]!=-1)
                                    printf("%c",temp[w]+'a');
                                else
                                {
                                    for(int j1=0;j1<k;j1++)
                                    {
                                        if(!taken[j1])
                                        {
                                            taken[j1]=true;
                                            printf("%c",j1+'a');
                                            break;
                                        }
                                    }
                                }
                            }
                            printf("\n");
                            return;
            }
            for(int das=0;das<k;das++)
            {
                temp[das]=t1[das];
                taken[das]=t2[das];
            }
            if((temp[s[i]]==-1&&taken[b[i]]==false)||temp[s[i]]==b[i])
            {
                temp[s[i]]=b[i];
                taken[b[i]]=true;
            }
            else
            {
                printf("NO\n");
                return;
            }
            for(int j=i+1;j<n;j++)
            {
                if(temp[s[j]]==-1)
                {
                    for(int d=0;d<b[j];d++)
                    {
                        if(!taken[d])
                        {
                            temp[s[j]]=d;
                            taken[d]=true;
                            printf("YES\n");
                            for(int w=0;w<k;w++)
                            {
                                if(temp[w]!=-1)
                                    printf("%c",temp[w]+'a');
                                else
                                {
                                    for(int j1=0;j1<k;j1++)
                                    {
                                        if(!taken[j1])
                                        {
                                            taken[j1]=true;
                                            printf("%c",j1+'a');
                                            break;
                                        }
                                    }
                                }
                            }
                            printf("\n");
                            return;
                        }
                    }
                    if(taken[b[j]])
                    {
                        printf("NO\n");
                        return;
                    }
                    else
                    {
                        temp[s[j]]=b[j];
                        taken[b[j]]=true;
                    }
                }
                else
                {
                    if(temp[s[j]]<b[j])
                    {
                        printf("YES\n");
                            for(int w=0;w<k;w++)
                            {
                                if(temp[w]!=-1)
                                    printf("%c",temp[w]+'a');
                                else
                                {
                                    for(int j1=0;j1<k;j1++)
                                    {
                                        if(!taken[j1])
                                        {
                                            taken[j1]=true;
                                            printf("%c",j1+'a');
                                            break;
                                        }
                                    }
                                }
                            }
                            printf("\n");
                            return;
                    }
                    if(temp[s[j]]>b[j])
                    {
                        printf("NO\n");
                        return;
                    }
                }
            }
            printf("YES\n");
                            for(int w=0;w<k;w++)
                            {
                                if(temp[w]!=-1)
                                    printf("%c",temp[w]+'a');
                                else
                                {
                                    for(int j1=0;j1<k;j1++)
                                    {
                                        if(!taken[j1])
                                        {
                                            taken[j1]=true;
                                            printf("%c",j1+'a');
                                            break;
                                        }
                                    }
                                }
                            }
                            printf("\n");
                            return;
        }
    }
    printf("YES\n");
    for(int w=0; w<k; w++)
    {
        //printf("Testiram %i\n",w);
        if(temp[w]!=-1)
            printf("%c",temp[w]+'a');
        else
        {
            for(int j=0; j<k; j++)
            {
                if(!taken[j])
                {
                    taken[j]=true;
                    printf("%c",j+'a');
                    break;
                }
            }
        }
    }
    printf("\n");
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	//scanf("%i",&t);
	while(t--)
        test();
    return 0;
}