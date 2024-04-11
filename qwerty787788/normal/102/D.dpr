const md = 1000000007;
var
tmp:int64;
j,dd,n,m,i:longint;
pair,pr,next,l,r,a,num:array[0..400000]of longint;
count,ans:array[0..4000000]of int64;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[l+random(r-l)];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;

                y:=num[i];
                num[i]:=num[j];
                num[j]:=y;

                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

 begin
  read(n,m);
  for i:=1 to m do
    begin
     read(a[i*2-1],a[i*2]);
    end;
  for i:=1 to m+m do num[i]:=i;

  sort(1,2*m);

  dd:=0;
  a[0]:=-1;
  for i:=1 to m+m do
    begin
     if a[i]>a[i-1] then dd:=dd+1;
     if odd(num[i]) then l[(num[i]+1)div 2]:=dd
                    else r[num[i] div 2]:=dd;
    end;

  if (a[1]<>0)or(a[m+m]<>n) then
    begin
     writeln(0);
     halt(0);
    end;

  for i:=1 to m do
   begin
    count[r[i]]:=count[r[i]]+1;
    next[i]:=pr[l[i]];
    pair[i]:=r[i];
    pr[l[i]]:=i;
   end;

  ans[dd]:=1;
  tmp:=0;
  for i:=dd-1 downto 1 do
    begin
     tmp:=(tmp+ans[i+1]*count[i+1])mod md;
     j:=pr[i+1];
     while j>0 do
       begin
        tmp:=(tmp-ans[pair[j]]+md)mod md;
        j:=next[j];
       end;
     ans[i]:=tmp;
//     writeln(i,' ',ans[i]);
    end;
  writeln(ans[1]);
 end.