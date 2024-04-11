var
    a:array[1..4,1..100002] of longint;
     n,v,i,ans,last1,last2:longint;


procedure quicksort(l,r:longint);
  var i,j,w,nom:longint; d:extended;
begin
  i:=l; j:=r; nom:=random(r-l+1)+l;
  d:=a[2,nom]/a[1,nom];
  while i<=j do
    begin
      while (a[2,i]/a[1,i])<d do inc(i);
      while (a[2,j]/a[1,j])>d do dec(j);
      if i<=j then
        begin
          w:=a[1,i]; a[1,i]:=a[1,j]; a[1,j]:=w;
          w:=a[2,i]; a[2,i]:=a[2,j]; a[2,j]:=w;
          w:=a[3,i]; a[3,i]:=a[3,j]; a[3,j]:=w;
          inc(i); dec(j);
        end;
    end;
  if i<r then quicksort(i,r);
  if l<j then quicksort(l,j);
end;


begin

  readln(n,v);
  for i:=1 to n do
    begin
      readln(a[1,i],a[2,i]);
      a[3,i]:=i;
    end;
  randomize; quicksort(1,n);

  ans:=0; last1:=n+1; last2:=n+2; a[2,n+1]:=1000000000; a[2,n+2]:=1000000000;
  for i:=n downto 1 do
    if v>=a[1,i] then
      begin
        ans:=ans+a[2,i]; v:=v-a[1,i]; a[4,i]:=1;
        if a[1,i]=1 then last1:=i;
      end
        else
      begin
        if (v=1) and (a[1,i]=2) and (a[2,last1]<a[2,i]) then
          begin
            v:=0; ans:=ans+(a[2,i]-a[2,last1]);
            a[4,i]:=1; a[4,last1]:=0;
          end
            else
          begin
            if (v=0) and (a[1,i]=1) and (last1<>n+1) and (a[2,last1]+a[2,i]>a[2,last2]) then
              begin
                ans:=ans+(a[2,last1]+a[2,i])-a[2,last2]; a[4,last2]:=0;
                a[4,last1]:=1; a[4,i]:=1; last2:=n+2;
              end;
          end;
      end;

  writeln(ans);
  for i:=1 to n do
    if a[4,i]=1 then write(a[3,i],' ');
end.