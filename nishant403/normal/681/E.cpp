#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

const double PI = acos(-1);
const double EPS = 1e-9;

int dis(pair<int,int> a,pair<int,int> b)
{
 return  (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second) ;   
}

signed main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
     int T,v;
     pair<int,int> C;    
    
    
     cin >> C.first >> C.second >> T >> v;
        
    int R = 1.00*v*T;
     
       int n;
       cin >> n;
        
     vector<pair<double,int> > cut;
     pair<int,int> center;
     int radi;
    
      for(int i=0;i<n;i++)  
      {
         cin >> center.first >> center.second >> radi;
          
         int distance = dis(center,C); 
             
         if(distance < radi*radi + EPS) {cout << fixed << setprecision(6) << 1.0000000; return 0; } 
          
         if( sqrt(distance) - EPS > 1.00*radi + 1.00*R) continue; 
        
         double angletocenter =atan2(center.second - C.second , center.first - C.first );   
          
         if(angletocenter < 0 ) angletocenter+=(2*PI);
          
        double tangent_length = sqrt( distance - (1.00*radi*radi) );   
          
        double diverge_angle;  
          
        if(tangent_length < 1.00*R + EPS) diverge_angle = asin(radi/sqrt(distance));  
        else  diverge_angle = acos( ( (distance) - (radi*radi) + (1.00*R*R) )/(2*sqrt(distance)*R)  );
          
        
       double left = angletocenter - diverge_angle; 
       double right = angletocenter + diverge_angle;
          
              
     if(left < 0 )
     {
         cut.pb({left+2*PI,1});
         cut.pb({2*PI,-1});
        cut.pb({0.00,1});
        cut.pb({right,-1});
     }
          
     else if(right > 2*PI)
     {
         cut.pb({left,1});
         cut.pb({2*PI,-1});
         cut.pb({right-2*PI,-1});
         cut.pb({0.00,1});
     }
          
     else cut.pb({left,1}),cut.pb({right,-1});
      }        
          
    //process cuts and add angle to ans
    double ans = 0.00;
    int count = 0;
    double last = 0;
    
    sort(cut.begin(),cut.end());                              
  
   for(auto &x : cut)
   {
  if(count>0) ans+=(x.first - last);
    last=x.first;   
   count+=(x.second);
  }
    
      cout << fixed << setprecision(6) << (ans/(2*PI)) ;       
}