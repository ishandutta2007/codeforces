var
    a:array[1..100000] of longint; used:array[1..100000] of boolean; ans,n,s,t,i:longint;


begin

  readln(n,s,t); for i:=1 to n do read(a[i]);
  ans:=0; used[s]:=true; i:=s;
  while true do
    begin
      if i=t then begin writeln(ans); halt; end;
      i:=a[i]; inc(ans);
      if used[i]=true then begin writeln(-1); halt; end else used[i]:=true;
    end;

end.