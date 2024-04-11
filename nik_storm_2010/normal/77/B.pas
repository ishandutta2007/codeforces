var
  tests,now:longint;
  a,b,all,p,q,ans:extended;

begin
  read(tests);
  for now:=1 to tests do
  begin
    readln(a,b);
    if (a=0) and (b=0) then begin writeln(1.0:0:8); continue; end;
    if (a=0) then
    begin
      writeln(0.5:0:8);
      continue;
    end;
    if (b=0) then
    begin
      writeln(1.0:0:8);
      continue;
    end;
    all:=a*2*b;
    q:=a/4;
    p:=4*b;
    if (q<=b) then ans:=(a*b+a*q/2)/all else ans:=(a*b+b*(a-p)+p*b/2)/all;
    writeln(ans:0:8)
  end;
end.