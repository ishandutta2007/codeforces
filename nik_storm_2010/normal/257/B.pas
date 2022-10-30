var
    a:array[1..200000] of longint; kp1,kp2,kv1,kv2,tn,tm,n,m:longint;


procedure resultofgame(var kolp,kolv:longint);
var i:longint;
begin
  kolv:=0; kolp:=0;
  for i:=2 to n+m do if i mod 2=0 then
    begin
      if a[i-1]=1 then
        begin
          if tm<>0 then begin a[i]:=2; dec(tm); inc(kolv); end
                   else begin a[i]:=1; dec(tn); inc(kolp); end;
        end
          else
        begin
          if tn<>0 then begin a[i]:=1; dec(tn); inc(kolv); end
                   else begin a[i]:=2; dec(tm); inc(kolp); end;
        end;
    end
      else
    begin
      if a[i-1]=1 then
        begin
          if tn<>0 then begin a[i]:=1; dec(tn); inc(kolp); end
                   else begin a[i]:=2; dec(tm); inc(kolv); end;
        end
          else
        begin
          if tm<>0 then begin a[i]:=2; dec(tm); inc(kolp); end
                   else begin a[i]:=1; dec(tn); inc(kolv); end;
        end;
    end;
end;


begin

  readln(n,m);
  tn:=n-1; tm:=m; a[1]:=1; resultofgame(kp1,kv1);
  tn:=n; tm:=m-1; a[1]:=2; resultofgame(kp2,kv2);
  if kp1>kp2 then writeln(kp1,' ',kv1) else writeln(kp2,' ',kv2);

end.