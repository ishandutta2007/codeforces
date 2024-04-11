    {R+,S+,Q+,I+,O-}
    {$R-,S-,Q-,I-,O+}
    const md = round(1e9+7);
    var
      q,v,n,m,k,i,j: longint;
      cur,ans: int64;
      f,fi: array [0..1000010] of int64;
      g: array [0..1010,0..1010] of longint;

    function pow(a,b:longint):longint;
    var
      x,step: longint;
    begin
      x:=1; step:=1 shl 30;
      while step > b do step:=step shr 1;
      while step > 0 do
      begin
        x:=int64(x)*x mod md;
        if step and b <> 0 then x:=int64(x)*a mod md;
        step:=step shr 1;
      end;
      pow:=x;
    end;

    begin
    //  assign(input,'in'); reset(input);
    //  assign(output,'out'); rewrite(output);
      read(n,m,k);
      if m = 1 then
      begin
        ans:=1;
        for i:=1 to n do ans:=ans*k mod md;
        writeln(ans);
        halt;
      end;
      fillchar(g,sizeof(g),0);
      g[0,0]:=1;
      for i:=0 to n-1 do
        for j:=0 to i do
          if g[i,j] > 0 then
          begin
            g[i+1,j+1]:=(g[i+1,j+1]+g[i,j]) mod md;
            g[i+1,j]:=(g[i+1,j]+int64(g[i,j])*j) mod md;
          end;
      f[0]:=1;
      for i:=1 to 1000000 do f[i]:=f[i-1]*i mod md;
      for i:=0 to 2000 do fi[i]:=pow(f[i],md-2);
      for i:=k-2000 to k do
        if i > 2000 then fi[i]:=pow(f[i],md-2);
      ans:=0;
      for q:=0 to n do
        for v:=0 to n-q do
        begin
          if (m > 2) and (v = 0) then continue;
          if q+q+v > k then continue;
          cur:=f[k]*fi[q] mod md*fi[q] mod md*fi[v] mod md*fi[k-q-q-v] mod md;
          cur:=cur*g[n,q+v] mod md*g[n,q+v] mod md;
          cur:=cur*f[q+v] mod md*f[q+v] mod md;
          cur:=cur*pow(v,n*(m-2)) mod md;
          ans:=(ans+cur) mod md;
        end;
      writeln(ans);
      close(input);
      close(output);
    end.