var
  d,k1,k2,k3,n1,n2,n3,p1,p2,p3,r,full,need,ans:int64;
  i:longint;
  s:string;

begin
  readln(s);
  d:=length(s);
  for i:=1 to d do
  begin
    if (s[i]='B') then inc(k1);
    if (s[i]='S') then inc(k2);
    if (s[i]='C') then inc(k3);
  end;
  readln(n1,n2,n3);
  readln(p1,p2,p3);
  readln(r);
  full:=k1*p1+k2*p2+k3*p3;
  while true do
  begin
    need:=0;
    if (k1<>0) then
    begin
      if (n1>k1) then n1:=n1-k1 else begin need:=need+(k1-n1)*p1; n1:=0; end;
    end;
    if (k2<>0) then
    begin
      if (n2>k2) then n2:=n2-k2 else begin need:=need+(k2-n2)*p2; n2:=0; end;
    end;
    if (k3<>0) then
    begin
      if (n3>k3) then n3:=n3-k3 else begin need:=need+(k3-n3)*p3; n3:=0; end;
    end;
    if (need=full) or (need>r) then break;
    r:=r-need;
    inc(ans);
  end;
  writeln(ans+r div full);
end.