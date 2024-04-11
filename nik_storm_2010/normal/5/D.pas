const e=0.000001;
var
  ans,ca,cb,cc,cd,lb,mb,rb,t1,t2,s1,s2,a,v,l,d,w,t,s:extended;


begin

  readln(a,v); readln(l,d,w);
  if (v<=w) then
  begin
    t:=v/a; s:=a*t*t/2;
    if s<=l then ans:=t+(l-s)/v else ans:=sqrt(2*l/a);
  end
    else
  begin
    t:=w/a; s:=a*t*t/2;
    if d<=s then
    begin
      t:=v/a; s:=a*t*t/2;
      if s<=l then ans:=t+(l-s)/v else ans:=sqrt(2*l/a);
    end
      else
    begin
      lb:=w; rb:=v;
      while (rb-lb>=e) do
      begin
        mb:=(lb+rb)/2;
        t1:=mb/a; t2:=(mb-w)/a;
        s1:=a*t1*t1/2; s2:=mb*t2-a*t2*t2/2;
        if (s1+s2<=d) then lb:=mb else rb:=mb;
      end;
      t1:=lb/a; t2:=(lb-w)/a;
      s1:=a*t1*t1/2; s2:=lb*t2-a*t2*t2/2;
      ans:=t1+t2+(d-s1-s2)/lb;
      t:=(v-w)/a; s:=w*t+a*t*t/2;
      if s<=(l-d) then ans:=ans+t+(l-d-s)/v else
      begin
        ca:=a/2; cb:=w; cc:=-l+d; cd:=cb*cb-4*ca*cc;
        t1:=(-cb-sqrt(cd))/(2*ca);
        t2:=(-cb+sqrt(cd))/(2*ca);
        if t1>0 then ans:=ans+t1 else ans:=ans+t2;
      end;
    end;
  end;
  writeln(ans:0:6);

end.