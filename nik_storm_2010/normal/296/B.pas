const module=1000000007;
var
    s,w:ansistring; q,n,cur,ans,k1,k2,k3:int64; i:longint;


function small(i:longint):int64;
begin
  if (s[i]='?') and (w[i]='?') then exit(55);
  if (s[i]='?') then exit(ord(w[i])-47);
  if (w[i]='?') then exit(58-ord(s[i]));
  if (s[i]<=w[i]) then exit(1) else exit(0);
end;


function lager(i:longint):int64;
begin
  if (s[i]='?') and (w[i]='?') then exit(55);
  if (s[i]='?') then exit(58-ord(w[i]));
  if (w[i]='?') then exit(ord(s[i])-47);
  if (s[i]>=w[i]) then exit(1) else exit(0);
end;


function same(i:longint):int64;
begin
  if (s[i]='?') and (w[i]='?') then exit(10);
  if (s[i]='?') then exit(1);
  if (w[i]='?') then exit(1);
  if (s[i]=w[i]) then exit(1) else exit(0);
end;


begin

  readln(n); readln(s); readln(w); q:=0;
  for i:=1 to n do
  begin
    if s[i]='?' then inc(q);
    if w[i]='?' then inc(q);
  end;
  k1:=1; k2:=1; k3:=1;
  for i:=1 to n do
    begin
      k1:=(k1*small(i)) mod module;
      k2:=(k2*lager(i)) mod module;
      k3:=(k3*same(i)) mod module;
    end;
  ans:=1;
  for i:=1 to q do ans:=(ans*10) mod module;
  cur:=k1+k2-k3;
  if cur<0 then cur:=cur+module;
  ans:=ans-cur;
  if ans<0 then ans:=ans+module;
  writeln(ans);

end.