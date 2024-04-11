var
    a:array[1..100] of char; used:array[1..100] of boolean; tek,n,t,i:longint;


begin

  readln(n,t); for i:=1 to n do read(a[i]);
  for tek:=1 to t do
    begin
      fillchar(used,sizeof(used),false);
      for i:=1 to n-1 do
        if (a[i]='B') and (a[i+1]='G') and (used[i]=false) and (used[i+1]=false) then
        begin
          a[i]:='G'; a[i+1]:='B';
          used[i]:=true; used[i+1]:=true;
        end;
    end;
  for i:=1 to n do write(a[i]);

end.