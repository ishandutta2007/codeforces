var
    ans:extended; aa,ba,a,b,x,y,n:longint;


begin

  readln(x,y,n); ans:=x/y; aa:=0; ba:=1; a:=0; b:=1;
  while true do
    begin
      if abs((a+1)/b-x/y)<abs(a/b-x/y) then inc(a) else inc(b);
      if b=n+1 then break;
      if ans>abs(a/b-x/y) then begin ans:=abs(a/b-x/y); aa:=a; ba:=b end;
      if ans=0 then break;
    end;
  writeln(aa,'/',ba);

end.