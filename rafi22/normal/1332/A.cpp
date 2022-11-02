    #include <iostream>
     
    using namespace std;
     
    int main()
    {
        int t,a,b,c,d,x,y,x1,y1,x2,y2;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>a>>b>>c>>d;
            cin>>x>>y>>x1>>y1>>x2>>y2;
            bool q=1;
            if(a!=0||b!=0)
            {
                //cout<<a-b<<endl;
                if(a-b==0)
                {
                    if(x1==x2) q=0;
                }
                else if(a-b>0)
                {
                    if(x-(a-b)<x1) q=0;
                }
                else
                {
                    if(x+abs(a-b)>x2) q=0;
                }
            }
            if(c!=0||d!=0)
            {
                if(c-d==0)
                {
                    if(y1==y2) q=0;
                }
                else if(c-d>0)
                {
                    if(y-(c-d)<y1) q=0;
                }
                else
                {
                    if(y+abs(c-d)>y2) q=0;
                }
            }
            if(q) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            /*if(a>b)
            {
                if(x-max((a-b),1)>=x1)
                {
                    if(c>d)
                    {
                        if(c==0) cour
                        if(y-max((c-d),1)>=y1)
                            cout<<"YES"<<endl;
                        else cout<<"NO"<<endl;
                    }
                    else
                    {
                        if(d==0) cout<<"YES"<<endl;
                        else
                        {
                            if(y+max((d-c),1)<=y2)
                                cout<<"YES"<<endl;
                            else cout<<"NO"<<endl;
                        }
                    }
                }
                else cout<<"NO"<<endl;
            }
            else
            {
                if(x+max((b-a),1)<=x2)
                {
                    if(c>d)
                    {
                        if(c==0) cout<<"YES"<<endl;
                        else
                        {
                            if(y-max((c-d),1)>=y1)
                            cout<<"YES"<<endl;
                            else cout<<"NO"<<endl;
                        }
     
                    }
                    else
                    {
                        if(d==0) cout<<"YES"<<endl;
                        else
                        {
                            if(y+max((d-c),1)<=y2)
                                cout<<"YES"<<endl;
                            else cout<<"NO"<<endl;
                        }
                    }
                }
                else cout<<"NO"<<endl;
            }*/
        }
     
        return 0;
    }