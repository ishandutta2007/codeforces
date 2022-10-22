uses math;

var n,m,p,q     : int64;
    l,r         : longint;
    i,j,k       : longint;
    x,y         : int64;
    cnt,ans     : int64;
    a           : array[0..9] of longint;
    s,s1,s2,c   : ansistring;
    b           : boolean;

procedure fill(k,t : longint);

begin
     if t = 0 then exit;
     x := x * 10 + k;
     fill(k,t-1);
end;

begin
     readln(s1);
     readln(s2);

     for i := 1 to length(s1) do
     begin
          val(s1[i],j);
          inc(a[j]);
     end;

     val(s2,y);

     ans := 0;

     for i := 1 to length(s1) do
     begin
          for j := 9 downto 0 do
          begin
               x := ans;
               if a[j] > 0
               then begin
                         x := ans * 10 + j;
                         for k := 0 to 9 do
                             if k = j
                             then fill(k,a[k]-1)
                             else fill(k,a[k]);
                         if x <= y
                         then begin
                                   ans := ans * 10 + j;
                                   dec(a[j]);
                                   break;
                              end;
                    end;
          end;
     end;

     writeln(ans);
end.