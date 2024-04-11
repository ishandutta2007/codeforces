#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%i",&t);
    for(int l=0;l<t;l++)
    {
        int n;
        scanf("%i",&n);
        vector<int> stapovi;
        map<int,int> mapa;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%i",&x);
            mapa[x]++;
            if(mapa[x]==2||mapa[x]==4)
            {
                stapovi.push_back(x);
                //printf("Dodajem %i\n",x);
            }
        }
        double minn=0;
        int x,y;
        sort(stapovi.begin(),stapovi.end());
        for(int i=1;i<stapovi.size();i++)
        {

            int razlika=stapovi[i]-stapovi[i-1];
            if(razlika==0)
            {
                x=stapovi[i];
                y=stapovi[i];
                break;

            }
            double lol=(double)stapovi[i]/(double)razlika;
            //printf("Gledam %i %i, razlika:%i, x: %f\n",stapovi[i],stapovi[i-1],razlika,lol);
            if(lol>minn)
            {
                x=stapovi[i];
                y=stapovi[i-1];
                minn=lol;
            }
        }
        printf("%i %i %i %i\n",x,x,y,y);
    }
    return 0;
}